import re
import numpy as np

instructions = [
  "nop", "ldr", "str", "lpt",
  "spt", "cmp", "add", "sub",
  "mul", "div", "mod", "and",
  "or",  "xor", "not", "lsl",
  "lsr", "psh", "pop", "pek",
  "jmp", "jsr", "rts", "joc",
  "jsc", "rsc"
]

registers = [
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
]

def printWord(word):
  data = word[0] | (word[1] << 8) | (word[2] << 16) | (word[3] << 24)
  data = '{:032b}'.format(data)
  # print(data)
  # w1 = data[:2] + '_' + data[2:6] + '_' + data[6:9] + '_' + data[9:12] + '_' + data[12:15]
  # w2 = data[15:23] + '_' + data[23:31]
  # print(w1)
  # print(w2)
  print(data[16:19], end='_')
  print(data[19:22], end='_')
  print(data[22:25], end='_')
  print(data[25:30], end='_')
  print(data[30:])
  print(data[:8], end='_')
  print(data[8:16], end=' ')
  print('(0x{:04X}, {})'.format(word[2] | (word[3] << 8), word[2] | (word[3] << 8)))
  print()

def varToLine(varName, preserved):
  for i in range(len(preserved)):
    if varName in preserved[i][1]:
      return preserved[i][0]

def findMulti(str, arr, start, depth):
  for i in range(start, -1, -1):
    if str == arr[i][depth]:
      return i
  return -1

def find(str, arr):
  for i in range(len(arr)):
    if str == arr[i]:
      return i
  return -1

def ismathy(line, start):
  math = re.compile('[+\\-=/\\*\\(\\)<>\\|\\&\\^]')
  for i in range(len(line) - start):
    if math.search(line[start + i]) != None:
      return True
  return False

def inst2word(instruction):
  word = [0, 0, 0, 0]
  word[0] = (instruction[0] | (instruction[1] << 7)) & 255
  word[1] = ((instruction[1] >> 1) | (instruction[2] << 2) | (instruction[3] << 5)) & 255
  word[2] = (instruction[4] & 255) & 255
  word[3] = ((instruction[4] >> 8) & 255) & 255
  return word

def writeVerilog(code, outfile):
  with open(outfile, 'w') as file:
    file.write('module romdata(\n')
    file.write('    input wire CLK,\n')
    file.write('    input wire [15:0] address,\n')
    file.write('    output wire [31:0] data\n')
    file.write('  );\n\n')
    file.write('  // Xilinx style block ram directive\n')
    file.write('  (* rom_style = \"block\" *) reg [31:0] dintern = 32\'b0;\n\n')
    file.write('  always @( * ) begin\n')
    file.write('    case (address)\n')
    # print(code)
    for i in range(len(code)):
      data = code[i][0] | (code[i][1] << 8) | (code[i][2] << 16) | (code[i][3] << 24)
      line = '      16\'h{:04X}: dintern = 32\'h{:08X};\n'.format(i, data)
      file.write(line)
    file.write('      default: dintern = 32\'h0;\n')
    file.write('    endcase\n')
    file.write('  end\n\n')
    file.write('  assign data = dintern;\n\n')
    file.write('endmodule\n')

def write(code, outfile):
  arr = np.array(code, dtype='u1')
  arr = arr.tobytes()
  with open(outfile, 'wb') as file:
    file.write(arr)

def encode(lines, variables, preserved, dict):
  conditions = [
    'zero',
    'carry',
    'negative',
    'equal',
    'greater',
    'less',
    # 'greateq',
    # 'lesseq'
  ]
  code = []
  for i in range(len(lines)):
    opcode = find(lines[i][2][0], instructions)
    inst = [0, 0, 0, 0, 0]
    if opcode == -1:
      errstr = "-> invalid instruction \'{}\'".format(lines[i][2][0])
      err(preserved, lines[i][0], errstr, 2)
    if opcode == 0: # nop
      pass
    if opcode == 1: # LDR
      inst = [opcode << 2, 0, 0, 0, 0]
      res = find(lines[i][2][1], registers)
      if res == -1:
        errstr = "-> invalid register \'{}\' for results".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      inst[3] = res
      if str(lines[i][2][2]).isnumeric(): # what about hex/bin literals?
        inst[0] |= 2
        inst[4] = int(lines[i][2][2])
      elif ismathy(lines[i][2][2], 0):
        inst[0] |= 2
        solution = 0
        try:
          solution = round(eval(lines[i][2][2], {}, dict))
        except NameError:
          errstr = "-> undefined assignment"
          err(preserved, lines[i][0], errstr, 2)
        except SyntaxError:
          errstr = "-> invalid syntax"
          err(preserved, lines[i][0], errstr, 2)
        except AttributeError:
          errstr = "-> scope does not contain element"
          err(preserved, lines[i][0], errstr, 2)
        except TypeError:
          errstr = "-> undefined assignment"
          err(preserved, lines[i][0], errstr, 2)
        inst[4] = solution
      else:
        found = False
        for variable in variables:
          if lines[i][2][2] == variable[1]:
            inst[0] |= 2
            inst[4] = int(variable[2])
            found = True
            break
          elif lines[i][2][2] == variable[2]:
            if 'const' in variable[0]:
              inst[0] |= 1
            inst[4] = int(variable[1])
            found = True
            break
        if not found:
          errstr = "-> undefined argument \'{}\'".format(lines[i][2][2])
          err(preserved, lines[i][0], errstr, 2)
    elif opcode == 2: # STR
      inst = [opcode << 2, 0, 0, 0, 0]
      op1 = find(lines[i][2][1], registers)
      if op1 == -1:
        errstr = "-> invalid register \'{}\' for operand".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      inst[1] = op1
      if len(lines[i][2]) != 3 or str(lines[i][2][2]).isnumeric():
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      for variable in variables:
        found = False
        if lines[i][2][2] == variable[2]:
          if 'const' in variable[0]:
            errstr = "-> argument \'{}\' must be a RAM address".format(lines[i][2][2])
            err(preserved, lines[i][0], errstr, 2)
          inst[4] = int(variable[1])
          found = True
          break
        elif lines[i][2][2] == variable[1]:
          errstr = "-> argument \'{}\' must be a RAM address".format(lines[i][2][2])
          err(preserved, lines[i][0], errstr, 2)
      if not found:
        errstr = "-> undefined argument \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 2)
    elif opcode == 3 or opcode == 4: # LPT, SPT
      inst = [opcode << 2, 0, 0, 0, 0]
      res = find(lines[i][2][1], registers)
      if res == -1:
        errstr = "-> invalid register \'{}\' for results".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      if opcode == 3:
        inst[3] = res
      else:
        inst[1] = res
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      if lines[i][2][2] == 'RAM':
        pass
      elif lines[i][2][2] == 'ROM':
        inst[0] |= 1
      else:
        errstr = "-> \'{}\' must be set to \'RAM\' or \'ROM\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 2)
    elif opcode == 5: # CMP
      inst = [opcode << 2, 0, 0, 0, 0]
      if lines[i][2][1] in registers:
        inst[1] = find(lines[i][2][1], registers)
      else:
        errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      op2 = find(lines[i][2][2], registers)
      if op2 == -1:
        inst[0] |= 2
        if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
          inst[4] = int(lines[i][2][2])
        else:
          if ismathy(lines[i][2][2], 0):
            solution = 0
            try:
              solution = round(eval(lines[i][2][2], {}, dict))
            except NameError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            except SyntaxError:
              errstr = "-> invalid syntax"
              err(preserved, lines[i][0], errstr, 2)
            except AttributeError:
              errstr = "-> scope does not contain element"
              err(preserved, lines[i][0], errstr, 2)
            except TypeError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            inst[4] = solution
          else:
            for variable in variables:
              if lines[i][2][2] == variable[1]:
                inst[4] = int(variable[2])
                break
              elif lines[i][2][2] == variable[2]:
                errstr = "-> \'{}\' is not a register, literal, or macro".format(lines[i][2][2])
                err(preserved, lines[i][0], errstr, 2)
      else:
        inst[2] = op2
      if (len(lines[i][2]) > 3):
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
    elif opcode > 5 and opcode < 13: # mathematical operations
      inst = [opcode << 2, 0, 0, 0, 0]
      if lines[i][2][1] in registers:
        inst[1] = find(lines[i][2][1], registers)
      else:
        errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      op2 = find(lines[i][2][2], registers)
      if op2 == -1:
        inst[0] |= 2
        if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
          inst[4] = int(lines[i][2][2])
        else:
          if ismathy(lines[i][2][2], 0):
            solution = 0
            try:
              solution = round(eval(lines[i][2][2], {}, dict))
            except NameError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            except SyntaxError:
              errstr = "-> invalid syntax"
              err(preserved, lines[i][0], errstr, 2)
            except AttributeError:
              errstr = "-> scope does not contain element"
              err(preserved, lines[i][0], errstr, 2)
            except TypeError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            inst[4] = solution
          else:
            for variable in variables:
              if lines[i][2][2] == variable[1]:
                inst[4] = int(variable[2])
                break
              elif lines[i][2][2] == variable[2]:
                errstr = "-> \'{}\' is not a register, literal, or macro".format(lines[i][2][2])
                err(preserved, lines[i][0], errstr, 2)
      else:
        inst[2] = op2
      if (len(lines[i][2]) == 3):
        inst[3] = inst[1]
      else:
        res = find(lines[i][2][3], registers)
        if res == -1:
          errstr = "-> invalid register \'{}\' for results".format(lines[i][2][3])
          err(preserved, lines[i][0], errstr, 2)
        inst[3] = res
    elif opcode == 15 or opcode == 16: # lsl and lsr
      inst = [opcode << 2, 0, 0, 0, 0]
      if lines[i][2][1] in registers:
        inst[1] = find(lines[i][2][1], registers)
      else:
        errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
      op2 = find(lines[i][2][2], registers)
      if op2 == -1:
        inst[0] |= 2
        if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
          inst[4] = int(lines[i][2][2])
        else:
          if ismathy(lines[i][2][2], 0):
            solution = 0
            try:
              solution = round(eval(lines[i][2][2], {}, dict))
            except NameError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            except SyntaxError:
              errstr = "-> invalid syntax"
              err(preserved, lines[i][0], errstr, 2)
            except AttributeError:
              errstr = "-> scope does not contain element"
              err(preserved, lines[i][0], errstr, 2)
            except TypeError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 2)
            inst[4] = solution
          else:
            for variable in variables:
              if lines[i][2][2] == variable[1]:
                inst[4] = int(variable[2])
                break
              elif lines[i][2][2] == variable[2]:
                errstr = "-> \'{}\' is not a literal or macro".format(lines[i][2][2])
                err(preserved, lines[i][0], errstr, 2)
      else:
        errstr = "-> shift operations cannot accept register assignments for operand 2"
        err(preserved, lines[i][0], errstr, 2)
      if (len(lines[i][2]) == 3):
        inst[3] = inst[1]
      else:
        res = find(lines[i][2][3], registers)
        if res == -1:
          errstr = "-> invalid register \'{}\' for results".format(lines[i][2][3])
          err(preserved, lines[i][0], errstr, 2)
        inst[3] = res
    elif opcode == 20: # JMP
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      found = False
      for variable in variables:
        if lines[i][2][1] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
    elif opcode == 21: # JSR
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      for variable in variables:
        if lines[i][2][1] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 2)
    elif opcode == 22: # RTS
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 1:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)

    elif opcode == 23: # JOC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 2)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      found = False
      for variable in variables:
        if lines[i][2][2] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 2)
    if opcode == 24: # JSC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 2)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      found = False
      for variable in variables:
        if lines[i][2][2] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 2)
    elif opcode == 25: # RSC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 2)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
    code.append(inst2word(inst))
  return code

def addLabels(lines, variables, preserved):
  # adding proper addresses
  address = 0
  # for i in range(len(lines)):
  i = 0
  while i < len(lines):
    if ':' in lines[i][1]:
      # lines[i].insert(1, address)
      variables.append(['label', lines[i][1].strip(':'), address])
      lines.pop(i)
    else:
      lines[i].insert(1, address)
      op = lines[i][2].split()[0]
      tokens = lines[i][2][len(op):].split(',')
      for j in range(len(tokens) - 1, -1, -1):
        tokens[j] = tokens[j].strip()
        if tokens[j] == '':
          tokens.pop(j)
      tokens.insert(0, op)
      # print(tokens)
      lines[i][2] = tokens
      address += 1
      i += 1
  ramadd = 1024 # why not? enough space for stacks and memory-mapped io
  for i in range(len(variables)):
    if 'const' in variables[i][0]:
      variables[i].insert(1, address)
      address += 1
    elif 'sysvar' in variables[i][0]:
      variables[i].insert(1, int(variables[i][2]))
    elif 'var' in variables[i][0]:
      variables[i].insert(1, ramadd)
      ramadd += 1




def reorderInstructions(lines, infile):
  firstLine = ''
  done = False
  i = 0
  while not done:
    if lines[i][0].split()[0] != infile[:-4]:
      if firstLine == '':
        firstLine = lines[i][0]
      elif lines[i][0] == firstLine:
        done = True
        break
      temp = lines[i]
      lines.pop(i)
      lines.append(temp)
    else:
      i += 1
      if i == len(lines):
        done = True
        break

def cleanvars(lines, preserved):
  purge = ['def', 'var', 'const']
  for i in range(len(lines) - 1, -1, -1):
    tokens = lines[i][1].split()
    if tokens[0].strip(':') in purge:
      if ':' in lines[i][1]:
        errstr = "-> label must not use reserved key words"
        err(preserved, lines[i][0], errstr, 2)
      lines.pop(i)

# def encodeInstPass2(string, )
def convertVariables(lines, preserved, infile, dict):
  # hack? i think this is fine
  variables = [
    ['sysvar', 'STATUS', '0'],
    ['sysvar', 'STACK', '2'],
    ['sysvar', 'UART', '3'],
    ['sysvar', 'GPIO', '4'],
    ['sysvar', 'GPIO_DIR', '5'],
    ['macro', 'TX_EMPTY', '512'],
    ['macro', 'TX_FULL', '256'],
    ['macro', 'RX_EMPTY', '2048'],
    ['macro', 'RX_FULL', '1024'],
  ]
  dict['TX_EMPTY'] = 512
  dict['TX_FULL'] = 256
  dict['RX_EMPTY'] = 2048
  dict['RX_FULL'] = 1024
  # initializing array
  for i in range(len(lines)):
    tokens = lines[i][1].split()
    for j in range(len(tokens)):
      tokens[j] = tokens[j].strip(', ')
    if tokens[0] == 'def':
      if tokens[2] != '=': # this could be expanded
        errstr = "-> malformed definition"
        err(preserved, lines[i][0], errstr, 2)
      if len(tokens) > 4 or ismathy(tokens, 3):
        temp = ['macrocalc', tokens[1]]
        temptemp = ''
        for j in range(len(tokens) - 3):
          temptemp += tokens[3 + j]
        temp.append(temptemp)
        variables.append(temp)
      else:
        variables.append(['macro', tokens[1], tokens[3]])
    elif tokens[0] == 'var' or tokens[0] == 'const':
      if tokens[0] == 'const':
        if tokens[1] != 'var':
          errstr = "-> type error, expected \'var\' after \'const\'"
          err(preserved, lines[i][0], errstr, 2)
        if tokens[3] != '=' or len(tokens) < 5:
          errstr = "-> no assignment of const variable \'{}\'".format(tokens[2])
          err(preserved, lines[i][0], errstr, 2)
        if len(tokens) > 5 or ismathy(tokens, 4):
          temp = ['constcalc', tokens[2]]
          temptemp = ''
          for j in range(len(tokens) - 4):
            temptemp += tokens[4 + j]
          temp.append(temptemp)
          variables.append(temp)
        else:
          variables.append(['const', tokens[2], tokens[4]])
      elif tokens[0] == 'var':
        if tokens[1] == 'const':
          if tokens[3] != '=' or len(tokens) < 5:
            errstr = "-> no assignment of const variable \'{}\'".format(tokens[2])
            err(preserved, lines[i][0], errstr, 2)
          if len(tokens) > 5:
            temp = ['constcalc', tokens[2]]
            temptemp = ''
            for j in range(len(tokens) - 4):
              temptemp += tokens[4 + j]
            temp.append(temptemp)
            variables.append(temp)
          else:
            variables.append(['const', tokens[2], tokens[4]])
        else:
          if len(tokens) > 2:
            errstr = "-> non-const variable \'{}\' cannot be initialized".format(tokens[1])
            err(preserved, lines[i][0], errstr, 2)
          variables.append(['var', tokens[1]])
  # filling out array
  for i in range(len(variables)):
    if variables[i][0] == 'macro':
      # print(variables[i])
      if not variables[i][2].isnumeric():
        # print(variables[i])
        idx = findMulti(variables[i][2], variables, i, 1)
        if idx == -1:
          index = 0
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> undefined assignment \'{}\'".format(variables[i][2])
              err(preserved, varToLine(variables[i][1], preserved), errstr, 2)
        elif variables[idx][0] != 'macro' and variables[idx][0] != 'macrocalc':
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> macros only accept macro or literal assigment"
              err(preserved, preserved[j][0], errstr, 2)
        if '.' in variables[i][1]:
          name = variables[i][1][:variables[i][1].find('.')]
          attribute = variables[i][1][variables[i][1].find('.') + 1:]
          try:
            setattr(dict[name], attribute, int(variables[idx][2]))
          except KeyError:
            dict[name] = type(name, (object, ), {})
            setattr(dict[name], attribute, int(variables[idx][2]))
        else:
          dict[variables[i][1]] = int(variables[idx][2])
        variables[i][2] = variables[idx][2]
      else:
        if '.' in variables[i][1]:
          name = variables[i][1][:variables[i][1].find('.')]
          attribute = variables[i][1][variables[i][1].find('.') + 1:]
          try:
            setattr(dict[name], attribute, int(variables[i][2]))
          except KeyError:
            dict[name] = type(name, (object, ), {})
            setattr(dict[name], attribute, int(variables[i][2]))
            # print(dict[name].attribute, name, attribute)
        else:
          dict[variables[i][1]] = int(variables[i][2])
    elif variables[i][0] == 'macrocalc':
      solution = 0
      try:
        solution = round(eval(variables[i][2], {}, dict))
      except NameError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 2)
      except SyntaxError:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      except AttributeError:
        errstr = "-> scope does not contain element"
        err(preserved, lines[i][0], errstr, 2)
      except TypeError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 2)
      if '.' in variables[i][1]:
        name = variables[i][1][:variables[i][1].find('.')]
        attribute = variables[i][1][variables[i][1].find('.') + 1:]
        try:
          setattr(dict[name], attribute, solution)
        except KeyError:
          dict[name] = type(name, (object, ), {})
          setattr(dict[name], attribute, solution)
      else:
        dict[variables[i][1]] = solution
      variables[i][2] = solution
    elif variables[i][0] == 'const':
      if not variables[i][2].isnumeric():
        idx = findMulti(variables[i][2], variables, i - 1, 1)
        if idx == -1 or idx >= i:
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> undefined assignment \'{}\'".format(variables[i][2])
              err(preserved, preserved[j][0], errstr, 2)
        elif variables[idx][0] != 'macro' and variables[idx][0] != 'macrocalc':
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> const variables only accept macro or literal assigment"
              err(preserved, preserved[j][0], errstr, 2)
        variables[i][2] = variables[idx][2]
    elif variables[i][0] == 'constcalc':
      solution = 0
      try:
        # print(variables[i])
        # print(dict)
        solution = round(eval(variables[i][2], {}, dict))
      except NameError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 2)
      except SyntaxError:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 2)
      except AttributeError:
        errstr = "-> scope does not contain element"
        err(preserved, lines[i][0], errstr, 2)
      except TypeError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 2)
      variables[i][2] = solution
  return variables


def scope(lines, preserved, infile):
  var = re.compile('((?<=[^A-z_0-9\\.])|^)([A-z_][A-z_0-9]*)((?=[^A-z_0-9\\.])|$)')
  keywords = [
    'nop', 'ldr', 'str', 'lpt',
    'spt', 'cmp', 'add', 'sub',
    'mul', 'div', 'mod', 'and',
    'or',  'xor', 'not', 'lsl',
    'lsr', 'psh', 'pop', 'pek',
    'jmp', 'jsr', 'rts', 'joc',
    'jsc', 'rsc',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'def', 'var', 'const'
  ]
  for i in range(len(lines)):
    file = lines[i][0].split()[0]
    if file != infile[:-4]:
      match = var.search(lines[i][1])
      subindex = 0
      while match != None:
        target = lines[i][1][match.start() + subindex:match.end() + subindex]
        if target not in keywords:
          # print('not in keywords: {}'.format(target))
          # print(target)
          # exit(2)
          lines[i][1] = lines[i][1][:match.start() + subindex] + file + '.' + target + lines[i][1][match.end() + subindex:]
        else:
          # print('in keywords: {}'.format(target))
          subindex += match.end()
        match = var.search(lines[i][1][subindex:])


def repchr(string, insert, index):
  return string[:index] + insert + string[index + 1:]

def convertChars(lines):
  pass

def convertStrings(lines, preserved):
  unescApos = re.compile('(?<!\\\)\"')
  escaped = 0
  for i in range(len(lines)):
    match = unescApos.search(lines[i][1])
    if match != None:
      start = match.start()
      # next unescaped character:
      end = 0
      match = unescApos.search(lines[i][1][start + 1:])
      if (match == None):
        err(preserved, lines[i][0], "-> dangling string", 2)
      end = match.start() + start
      index = 0
      lines[i][1] = repchr(lines[i][1], '{ ', start)
      currentIndex = start + 2
      for j in range(end - start):
        # print(lines[i][1])
        insert = ''
        if (lines[i][1][currentIndex] == '\\'):
          if (escaped == 1):
            insert = "{}, ".format(ord(lines[i][1][currentIndex]))
          escaped ^= 1
        else:
          insert = "{}, ".format(ord(lines[i][1][currentIndex]))
        lines[i][1] = repchr(lines[i][1], insert, currentIndex)
        currentIndex += len(insert)
      lines[i][1] = repchr(lines[i][1], '}', currentIndex)


def copy2d(lines):
  ret  = []
  for i in range(len(lines)):
    line = []
    for j in range(len(lines[i])):
      line.append(lines[i][j])
    ret.append(line)
  return ret

def clean(lines):
  anything = re.compile('[A-z_0-9{}\"\'\\*\\/]')
  simpleComment = re.compile('^ *//')
  simpleBlock = re.compile('^ */\\*')
  for i in range(len(lines) - 1, -1, -1):
    if anything.search(lines[i][1]) == None or simpleComment.search(lines[i][1]) != None:
    # if anything.search(lines[i][1]) == None:
      lines.pop(i)

  index = 0
  removingBlock = 0
  while (index < len(lines)):
    if removingBlock == 0:
      if ('/*' in lines[index][1]):
        removingBlock = 1
        if simpleBlock.search(lines[index][1]) != None:
          start = lines[index][1].find('/*')
          if '*/' in lines[index][1]:
            end = lines[index][1].find('*/') + 2
            lines[index][1] = lines[index][1][:start] + lines[index][1][end:]
            removingBlock = 0
          else:
            lines[index][1] = lines[index][1][:start]
          if (anything.search(lines[index][1]) == None):
            lines.pop(index)
      else:
        index += 1
    else:
      if '*/' in lines[index][1]:
        end = lines[index][1].find('*/') + 2
        lines[index][1] = lines[index][1][end:]
        removingBlock = 0
        if (anything.search(lines[index][1]) == None):
          lines.pop(index)
      else:
        lines.pop(index)
  index = len(lines) - 1
  insideString = re.compile('\".*\"')
  while index > -1:
    if '//' in lines[index][1]:
      # checking to make sure double slash isn't inside string literal
      match = insideString.search(lines[index][1])
      if match == None or match.end() < lines[index][1].find('//'):
        lines[index][1] = lines[index][1][:lines[index][1].find('//')]
    index -= 1


def err(lines, key, message, exitcode):
  print("\nError in file \'{}\' at line {}:".format(key.split()[0], key.split()[1]))
  error = ''
  for line in lines:
    if key == line[0]:
      error = line[1]
      break
  print("  {}".format(error.strip(' \n')))
  print(message + '\n')
  exit(exitcode)

def insideExclusion(lines, lineindex, start, end):
  exclusionStartLine = 0
  exclusionStartChar = 0
  exclusionFound = False

  for i in range(len(lines)):
    if '/*' in lines[i][1] and not exclusionFound:
      if i > lineindex:
        break
      exclusionStartLine = i
      exclusionStartChar = lines[i][1].find("/*")
      exclusionFound = True
    if exclusionFound:
      if exclusionStartLine == lineindex:
        if exclusionStartChar < start and ("*/" not in lines[i][1] or lines[i][1].find('*/') > end):
          return True
      if '*/' in lines[i][1]:
        exclusionFound = False
      elif i == lineindex:
        if "*/" not in lines[i][1] or lines[i][1].find('*/') > end:
          return True
        else:
          break

  exclusionStartLine = 0
  exclusionStartChar = 0
  exclusionFound = False

  nonEscapedAstrophe = re.compile('(?<!\\\)\"')

  for i in range(len(lines)):
    if '\"' in lines[i][1] and not exclusionFound:
      if i > lineindex:
        break
      exclusionStartLine = i
      exclusionStartChar = lines[i][1].find('\"')
      exclusionFound = True
    if exclusionFound:
      firstpos = -1
      match = None
      if i == exclusionStartLine:
        match = nonEscapedAstrophe.search(lines[i][1][exclusionStartChar + 1:])
      else:
        match = nonEscapedAstrophe.search(lines[i][1])
      if match != None:
        firstpos = match.start()
      # print("{} EXCLUSION: {}, {}, {}".format(firstpos, i, lineindex, exclusionStartLine))
      if exclusionStartLine == lineindex:
        pos = -1
        match = nonEscapedAstrophe.search(lines[i][1][exclusionStartChar + 1:])
        if match != None:
          pos = match.start()
        if pos != -1:
          exclusionFound = False
        if exclusionStartChar < start and (pos == -1 or pos + exclusionStartChar > end):
          return True
        else:
          return False
      elif firstpos != -1:
        exclusionFound = False
      if i == lineindex:
        if firstpos == -1 or firstpos + exclusionStartChar > end:
          return True
        else:
          break

  return False

def expand(lines, infile):
  importPattern = re.compile('^ *import')
  index = 0
  imported = []
  while (index < len(lines)):
    if 'import' in lines[index][1]:
      if importPattern.search(lines[index][1]) != None:
        # print('import keyword found in file \"{}\" at line {}'.format(lines[index][0].split()[0], lines[index][0].split()[1]))
        start = lines[index][1].find('import')
        if not insideExclusion(lines, index, start, start + 6):
          name = ''
          tokens = lines[index][1].split()
          for i in range(len(tokens)):
            if tokens[i] == 'import':
              name = tokens[i + 1] + '.cor';
          # Error checking!

          if name == infile:
            err(lines, lines[index][0], "-> recursive import call", 2);
          elif name in imported:
            err(lines, lines[index][0], "-> file already imported", 2);

          imported.append(name)
          tokens = lines[index][1].split()
          tempname = name[:-4]
          if len(tokens) > 2 and tokens[2] == 'as':
            if len(tokens) != 4:
              err(lines, lines[index][0], "-> invalid import syntax", 2);
            tempname = tokens[3]
          templine = lines[index]
          lines.pop(index)
          try:
            with open(name, 'r') as file:
              numLines = 0
              for numLines, line in enumerate(file):
                lines.insert(index + numLines, ["{} {}".format(tempname, numLines + 1), line.strip(" \n")])
          except FileNotFoundError:
            file = templine[0].split()[0]
            num = templine[0].split()[1]
            print('Error in file \'{}\' at line {}:'.format(file, num))
            print('  {}'.format(templine[1].strip(' \n')))
            print("-> file \'{}\' not found".format(name))
            exit(2)
          index = -1
    index += 1
