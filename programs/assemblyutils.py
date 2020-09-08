import re
import numpy as np

instructions = [
  "nop", "ldr", "str", "lpt",
  "spt", "cmp", "add", "sub",
  "mul", "div", "mod", "and",
  "or",  "xor", "not", "lsl",
  "lsr", "psh", "pop", "pek",
  "jmp", "jsr", "rts", "joc",
  "jsc", "rsc", "tfm"
]

registers = [
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
]

def printDromWord(word):
  data = '{:016b}'.format(word)
  # print(data)
  # w1 = data[:2] + '_' + data[2:6] + '_' + data[6:9] + '_' + data[9:12] + '_' + data[12:15]
  # w2 = data[15:23] + '_' + data[23:31]
  # print(w1)
  # print(w2)
  print(data[:10], end='_')
  print(data[10:], end=', ')
  print('(0x{:04X}, {})'.format(word, word))
  print()

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
    if preserved[i][1].find(varName) != -1:
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

def isNumber(string):
  number = re.compile(r"^((0x[A-Fa-f0-9][A-Fa-f0-9_]*)|(0b[0-1][0-1_]*)|([1-9][0-9]*)|0)$")
  tok = string.split(' ')
  if len(tok) == 1 and number.search(tok[0]) != None:
    return True
  return False


def isbasey(line, start):
  base = re.compile(r"\b(0x|0b)")
  for i in range(len(line) - start):
    if base.search(line[start + i]) != None:
      return True
  return False

def ismathy(line, start):
  math = re.compile('[+\\-=/\\*\\(\\)<>\\|\\&\\^]')
  for i in range(len(line) - start):
    if math.search(line[start + i]) != None:
      return True
  return isbasey(line, start)



def inst2word(instruction):
  word = [0, 0, 0, 0]
  word[0] = (instruction[0] | (instruction[1] << 7)) & 255
  word[1] = ((instruction[1] >> 1) | (instruction[2] << 2) | (instruction[3] << 5)) & 255
  word[2] = (instruction[4] & 255) & 255
  word[3] = ((instruction[4] >> 8) & 255) & 255
  return word

def expandArrays(lines, preserved):
  vars = []
  # sanitizing arrays for easier processing
  tightBracket = re.compile(r"\{[^ ]")
  for i in range(len(lines)):
  #   for j in range(lenreversed(re.finditer(r"\{[^ ]", lines[i][1])):
  #     lines[i][1] = lines[i][1][:match.end()] + ' ' + lines[i][1][match.end():]
    matches = [match for match in tightBracket.finditer(lines[i][1])]
    # matches = [match for match in matches]
    if len(matches) > 0:
      # print("WOW")
      # print(matches)
      for j in range(len(matches) - 1, -1, -1):
        lines[i][1] = lines[i][1][:matches[j].end() - 1] + ' ' + lines[i][1][matches[j].end() - 1:]
  found = False
  numClosing = 0
  i = len(lines) - 1
  while i > -1:
    if not found and '}' in lines[i][1]:
      found = True
      numClosing = 0
    if found:
      found = False
      opening = False
      openingIndex = i # line index we'll use for iteration
      closingIndex = lines[i][1].rfind('}') - 1 # character index in line
      while not opening:
        if closingIndex == -1:
          openingIndex -= 1
          if openingIndex == -1:
            errstr = "-> unexpected closing bracket"
            err(preserved, lines[i][0], errstr, 69)
          closingIndex = len(lines[openingIndex][1]) - 1

        if lines[openingIndex][1][closingIndex] == '{':
          if numClosing == 0:
            if '[' not in lines[openingIndex][1]:
              errstr = '-> array initializer must include brackets \'[]\' to indicate dimensionality'
              err(preserved, lines[openingIndex][0], errstr, 70)
            opening = True
            break
          else:
            numClosing -= 1
        elif lines[openingIndex][1][closingIndex] == '}':
          numClosing += 1
        closingIndex -= 1
      if openingIndex < i:
        j = i
        while j > openingIndex:
          lines[j - 1][1] = lines[j - 1][1] + ' ' + lines[j][1]
          lines.pop(j)
          j -= 1
        i = openingIndex
    i -= 1
  # array expansion into useful structures
  onedim = re.compile(r"\[([1-9][0-9]*){0,1}\]")
  twodim = re.compile(r"\[([1-9][0-9]*){0,1}\]\[([1-9][0-9]*){0,1}\]")

  # This process is so scuffed -- we would already know exactly where arrays
  # are if we did this competently
  for i in range(len(lines) - 1, -1, -1):
    tokens = lines[i][1].split(' ')
    if len(tokens) > 1:
      match = onedim.search(tokens[1])
      if match != None:
        name = tokens[1][:match.start()]
        start = lines[i][1].find('{')
        end = lines[i][1].find('}')
        arr = lines[i][1][start + 1:end].split(',')
        for j in range(len(arr) - 1, -1, -1):
          arr[j] = arr[j].strip(' ')
          if arr[j] == '':
            arr.pop(j)
        # print('arr:', arr)
        for j in range(len(arr) - 1, -1, -1):
          templist = []
          templist.append(lines[i][0])
          if 'rom' in tokens[0]:
            templist.append('rom {}[{}] = {}'.format(name, j, arr[j]))
            # print(templist)
            lines.insert(i + 1, templist)
        lines.pop(i)
      elif twodim.search(lines[i][1]) != None:
        pass
    pass


def writeVerilogPROM(code, outfile):
  with open(outfile, 'w') as file:
    file.write('module promdata(\n')
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

def writeVerilogDROM(code, outfile):
  with open(outfile, 'w') as file:
    file.write('module dromdata(\n')
    file.write('    input wire CLK,\n')
    file.write('    input wire [15:0] address,\n')
    file.write('    output wire [15:0] data\n')
    file.write('    );\n\n')
    file.write('    (* rom_style = \"block\" *) reg [15:0] dintern = 16\'b0;\n\n')
    file.write('    always @( * ) begin\n')
    file.write('        case (address)\n')
    index = 0
    for i in range(len(code)):
      if 'const' in code[i][0]:
        # print(code[i])
        data = int(code[i][3])
        index = code[i][1]
        line = '      16\'h{:04X}: dintern = 16\'h{:08X};\n'.format(index, data)
        file.write(line)

    file.write('        default: dintern = 16\'h0;\n')
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
      err(preserved, lines[i][0], errstr, 3)
    if opcode == 0: # nop
      pass
    if opcode == 1: # LDR
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 4)
      inst = [opcode << 2, 0, 0, 0, 0]
      res = find(lines[i][2][1], registers)
      # needs expansion for loading pointers
      if res == -1:
        errstr = "-> invalid register \'{}\' for load".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 5)
      inst[3] = res
      # if str(lines[i][2][2]).isnumeric(): # what about hex/bin literals?
      if isNumber(str(lines[i][2][2])):
        # print(str(lines[i][2][2]))
        inst[0] |= 3 # immediate flag
        inst[4] = int(lines[i][2][2], 0)
      elif ismathy(lines[i][2][2], 0):
        inst[0] |= 3
        solution = 0
        try:
          solution = round(eval(lines[i][2][2], {}, dict))
        except NameError:
          errstr = "-> undefined assignment"
          err(preserved, lines[i][0], errstr, 6)
        except SyntaxError:
          errstr = "-> invalid syntax"
          err(preserved, lines[i][0], errstr, 7)
        except AttributeError:
          errstr = "-> scope does not contain element"
          err(preserved, lines[i][0], errstr, 8)
        except TypeError:
          errstr = "-> undefined assignment"
          err(preserved, lines[i][0], errstr, 9)
        inst[4] = solution
      else:
        found = False

        for variable in variables:
          # print(variable)
          if lines[i][2][2] == variable[1]:
            inst[0] |= 3 # immediate
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
          err(preserved, lines[i][0], errstr, 10)
    elif opcode == 2: # STR
      inst = [opcode << 2, 0, 0, 0, 0]
      op1 = find(lines[i][2][1], registers)
      if op1 == -1:
        errstr = "-> invalid register \'{}\' for operand".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 11)
      inst[1] = op1
      if len(lines[i][2]) != 3 or isNumber(str(lines[i][2][2])):
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 12)
      for variable in variables:
        found = False
        if lines[i][2][2] == variable[2]:
          if 'const' in variable[0]:
            errstr = "-> argument \'{}\' must be a RAM or GPU address".format(lines[i][2][2])
            err(preserved, lines[i][0], errstr, 13)
          inst[4] = int(variable[1])
          inst[0] |= 0 # if ram!!
          found = True
          break
        elif lines[i][2][2] == variable[1]:
          errstr = "-> argument \'{}\' must be a RAM or GPU address".format(lines[i][2][2])
          err(preserved, lines[i][0], errstr, 14)
      if not found:
        errstr = "-> undefined argument \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 15)
    elif opcode == 3 or opcode == 4: # LPT, SPT
      inst = [opcode << 2, 0, 0, 0, 0]
      res = find(lines[i][2][1], registers)
      if res == -1:
        errstr = "-> invalid register \'{}\' for results".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 16)
      if opcode == 3:
        inst[3] = res
      else:
        inst[1] = res
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 17)
      if lines[i][2][2] == 'ram':
        pass
      elif lines[i][2][2] == 'rom':
        inst[0] |= 1
        if opcode == 4:
          errstr = "-> cannot write to read-only memory"
          err(preserved, lines[i][0], errstr, 18)
      elif lines[i][2][2] == 'gpu':
        if opcode == 3:
          inst[0] |= 2
        elif opcode == 4:
          inst[0] |= 1
      else:
        errstr = "-> \'{}\' must be set to \'ram\', \'rom\', or \'gpu\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 19)
    elif opcode == 5: # CMP
      inst = [opcode << 2, 0, 0, 0, 0]
      if (len(lines[i][2]) != 3):
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 20)

      if lines[i][2][1] in registers:
        inst[1] = find(lines[i][2][1], registers)
      else:
        errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 21)
      op2 = find(lines[i][2][2], registers)
      if op2 == -1:
        if isinstance(lines[i][2][2], int) or isNumber(lines[i][2][2]):
        # if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
          inst[4] = int(lines[i][2][2], 0)
          inst[0] |= 3
        else:
          if ismathy(lines[i][2][2], 0):
            solution = 0
            try:
              solution = round(eval(lines[i][2][2], {}, dict))
            except NameError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 22)
            except SyntaxError:
              errstr = "-> invalid syntax"
              err(preserved, lines[i][0], errstr, 23)
            except AttributeError:
              errstr = "-> scope does not contain element"
              err(preserved, lines[i][0], errstr, 24)
            except TypeError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 25)
            inst[0] |= 3
            inst[4] = solution
          else:
            # print(lines[i][2][2])
            found = False
            for variable in variables:
              if lines[i][2][2] == variable[1]:
                found = True
                inst[0] |= 3
                inst[4] = int(variable[2])
                break
              elif lines[i][2][2] == variable[2]:
                found = True
                inst[0] |= 0
                inst[4] = int(variable[1])
                break
            if not found:
              errstr = "-> undefined argument \'{}\'".format(lines[i][2][2])
              err(preserved, lines[i][0], errstr, 26)
      else:
        inst[2] = op2
        inst[0] |= 1
    elif opcode > 5 and opcode < 13 or opcode == 15 or opcode == 16: # mathematicalish operations
      inst = [opcode << 2, 0, 0, 0, 0]
      if (len(lines[i][2]) != 3 and len(lines[i][2]) != 4):
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 27)

      if lines[i][2][1] in registers:
        inst[1] = find(lines[i][2][1], registers)
      else:
        errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 28)
      op2 = find(lines[i][2][2], registers)
      if op2 == -1:
        # inst[0] |= 2
        if isinstance(lines[i][2][2], int) or isNumber(lines[i][2][2]):
        # if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
          inst[4] = int(lines[i][2][2], 0)
          inst[0] |= 3
        else:
          if ismathy(lines[i][2][2], 0):
            solution = 0
            try:
              solution = round(eval(lines[i][2][2], {}, dict))
            except NameError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 29)
            except SyntaxError:
              errstr = "-> invalid syntax"
              err(preserved, lines[i][0], errstr, 30)
            except AttributeError:
              errstr = "-> scope does not contain element"
              err(preserved, lines[i][0], errstr, 31)
            except TypeError:
              errstr = "-> undefined assignment"
              err(preserved, lines[i][0], errstr, 32)
            inst[4] = solution
            inst[0] |= 3
          else:
            for variable in variables:
              if lines[i][2][2] == variable[1]: # macro
                found = True
                inst[0] |= 3
                inst[4] = int(str(variable[2]), 0)
                break
              elif lines[i][2][2] == variable[2]: # ram
                found = True
                # NOTE!! Const reading should be converted to
                # immediate reads, saving potential parameter space
                if 'const' in variable[0]:
                  errstr = " havent implemented const ops yet".format(lines[i][2][2])
                  err(preserved, lines[i][0], errstr, 33)
                inst[0] |= 0
                inst[4] = int(variable[1])
                break
            if not found:
              errstr = "-> undefined argument \'{}\'".format(lines[i][2][2])
              err(preserved, lines[i][0], errstr, 34)
      else:
        inst[2] = op2
        inst[0] |= 1
      if (len(lines[i][2]) == 3):
        inst[3] = inst[1]
      else:
        res = find(lines[i][2][3], registers)
        if res == -1:
          errstr = "-> invalid register \'{}\' for results".format(lines[i][2][3])
          err(preserved, lines[i][0], errstr, 35)
        inst[3] = res
    # elif opcode == 15 or opcode == 16: # lsl and lsr
    #   inst = [opcode << 2, 0, 0, 0, 0]
    #   if lines[i][2][1] in registers:
    #     inst[1] = find(lines[i][2][1], registers)
    #   else:
    #     errstr = "-> invalid register \'{}\' for operand 1".format(lines[i][2][1])
    #     err(preserved, lines[i][0], errstr, 2)
    #   op2 = find(lines[i][2][2], registers)
    #   if op2 == -1:
    #     inst[0] |= 2
    #     if isinstance(lines[i][2][2], int) or lines[i][2][2].isnumeric():
    #       inst[4] = int(lines[i][2][2])
    #     else:
    #       if ismathy(lines[i][2][2], 0):
    #         solution = 0
    #         try:
    #           solution = round(eval(lines[i][2][2], {}, dict))
    #         except NameError:
    #           errstr = "-> undefined assignment"
    #           err(preserved, lines[i][0], errstr, 2)
    #         except SyntaxError:
    #           errstr = "-> invalid syntax"
    #           err(preserved, lines[i][0], errstr, 2)
    #         except AttributeError:
    #           errstr = "-> scope does not contain element"
    #           err(preserved, lines[i][0], errstr, 2)
    #         except TypeError:
    #           errstr = "-> undefined assignment"
    #           err(preserved, lines[i][0], errstr, 2)
    #         inst[4] = solution
    #       else:
    #         for variable in variables:
    #           if lines[i][2][2] == variable[1]:
    #             inst[4] = int(variable[2])
    #             break
    #           elif lines[i][2][2] == variable[2]:
    #             errstr = "-> \'{}\' is not a literal or macro".format(lines[i][2][2])
    #             err(preserved, lines[i][0], errstr, 2)
    #   else:
    #     errstr = "-> shift operations cannot accept register assignments for operand 2"
    #     err(preserved, lines[i][0], errstr, 2)
    #   if (len(lines[i][2]) == 3):
    #     inst[3] = inst[1]
    #   else:
    #     res = find(lines[i][2][3], registers)
    #     if res == -1:
    #       errstr = "-> invalid register \'{}\' for results".format(lines[i][2][3])
    #       err(preserved, lines[i][0], errstr, 2)
    #     inst[3] = res
    elif opcode == 20: # JMP
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 36)
      found = False
      for variable in variables:
        if lines[i][2][1] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        # print(lines[i][2])
        # print(variables)
        errstr = "-> undefined label \'{}\'".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 37)
    elif opcode == 21: # JSR
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 38)
      found = False
      for variable in variables:
        if lines[i][2][1] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][1])
        err(preserved, lines[i][0], errstr, 39)
    elif opcode == 22: # RTS
      inst = [opcode << 2, 0, 0, 0, 0]
      if len(lines[i][2]) != 1:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 40)

    elif opcode == 23: # JOC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 41)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 42)
      found = False
      for variable in variables:
        if lines[i][2][2] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 43)
    if opcode == 24: # JSC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 44)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 3:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 45)
      found = False
      for variable in variables:
        if lines[i][2][2] == variable[1]:
          inst[4] = int(variable[2])
          found = True
          break
      if not found:
        errstr = "-> undefined label \'{}\'".format(lines[i][2][2])
        err(preserved, lines[i][0], errstr, 46)
    elif opcode == 25: # RSC
      inst = [opcode << 2, 0, 0, 0, 0]
      condition = find(lines[i][2][1], conditions)
      if condition == -1:
        errstr1 = "-> condition \'{}\' must be set to one of the following:".format(lines[i][2][1])
        errstr2 = "-> zero, carry, negative, equal, greater, less"
        err(preserved, lines[i][0], errstr1 + '\n' + errstr2, 47)
      inst[1] = (1 << condition) & 7
      inst[2] = (1 << condition) >> 3
      if len(lines[i][2]) != 2:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 48)
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
      variables.append(['label', lines[i][1].strip(': '), address])
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
  address =0
  # for i in range(len(variables)):
  #   if 'const' in variables[i][0]:
  #     variables[i].insert(1, address)
  #     address += 1
  #   elif 'sysvar' in variables[i][0]:
  #     variables[i].insert(1, int(variables[i][2]))
  #   elif 'var' in variables[i][0]:
  #     variables[i].insert(1, ramadd)
  #     ramadd += 1




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
  # purge = ['def', 'var', 'const']
  purge = ['pre', 'ram', 'rom']
  for i in range(len(lines) - 1, -1, -1):
    tokens = lines[i][1].split()
    if tokens[0].strip(':') in purge:
      if ':' in lines[i][1]:
        errstr = "-> label must not use reserved key words"
        err(preserved, lines[i][0], errstr, 49)
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
    if tokens[0] == 'pre':
      if tokens[2] != '=': # this could be expanded
        errstr = "-> malformed definition"
        err(preserved, lines[i][0], errstr, 50)
      if len(tokens) > 4 or ismathy(tokens, 3):
        temp = ['macrocalc', tokens[1]]
        temptemp = ''
        for j in range(len(tokens) - 3):
          temptemp += tokens[3 + j]
        temp.append(temptemp)
        variables.append(temp)
      else:
        variables.append(['macro', tokens[1], tokens[3]])
    # elif tokens[0] == 'var' or tokens[0] == 'const':
    # elif tokens[0] == 'ram' or tokens[0] == 'rom':
    elif tokens[0] == 'rom':
      # if tokens[1] != 'var':
      #   errstr = "-> type error, expected \'var\' after \'const\'"
      #   err(preserved, lines[i][0], errstr, 2)
      if tokens[2] != '=' or len(tokens) < 4:
        errstr = "-> no assignment of const variable \'{}\'".format(tokens[1])
        err(preserved, lines[i][0], errstr, 51)
      if len(tokens) > 4 or ismathy(tokens, 3):
        temp = ['constcalc', tokens[1]]
        temptemp = ''
        for j in range(len(tokens) - 3):
          temptemp += tokens[3 + j]
        temp.append(temptemp)
        variables.append(temp)
      else:
        variables.append(['const', tokens[1], tokens[3]])
    elif tokens[0] == 'ram':
      if len(tokens) > 2:
        errstr = "-> ram variable \'{}\' cannot be initialized".format(tokens[1])
        err(preserved, lines[i][0], errstr, 52)
      elif len(tokens) < 2:
        errstr = "-> ram type requires variable name for initialization"
        err(preserved, lines[i][0], errstr, 52)
      variables.append(['var', tokens[1]])
  # we'll likely need to enter the variable index here!
  address = 0
  ramadd = 1024 # address start for non-memory mapped data
  for i in range(len(variables)):
    if 'const' in variables[i][0]:
      variables[i].insert(1, address)
      address += 1
    elif 'sysvar' in variables[i][0]:
      variables[i].insert(1, int(variables[i][2]))
    elif 'var' in variables[i][0]:
      variables[i].insert(1, ramadd)
      ramadd += 1

  # adding silly ram/rom variable solution
  for i in range(len(variables) - 1, -1, -1):
    if 'const' in variables[i][0]:
      variables.insert(i + 1, ['macro', '$' + variables[i][2], str(variables[i][1])])
    elif 'var' in variables[i][0]:
      variables.insert(i + 1, ['macro', '$' + variables[i][2], str(variables[i][1])])

  # for variable in variables:
  #   print(variable)

  # filling out array
  for i in range(len(variables)):
    if variables[i][0] == 'macro':
      # print(variables[i])
      # if not variables[i][2].isnumeric():
      # print(variables[i], isNumber(variables[i][2]))
      if not isNumber(variables[i][2]):
        # print(variables[i])
        idx = findMulti(variables[i][2], variables, i, 1)
        if idx == -1:
          index = 0
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> undefined assignment \'{}\'".format(variables[i][2])
              err(preserved, varToLine(variables[i][1], preserved), errstr, 53)
        elif variables[idx][0] != 'macro' and variables[idx][0] != 'macrocalc':
          for j in range(len(preserved)):
            if variables[i][1] in preserved[j][1]:
              errstr = "-> macros only accept macro or literal assigment"
              err(preserved, preserved[j][0], errstr, 54)
        if '.' in variables[i][1]:
          name = variables[i][1][:variables[i][1].find('.')]
          attribute = variables[i][1][variables[i][1].find('.') + 1:]
          try:
            setattr(dict[name], attribute, int(variables[idx][2]))
          except KeyError:
            dict[name] = type(name, (object, ), {})
            setattr(dict[name], attribute, int(variables[idx][2], 0))
        else:
          dict[variables[i][1]] = int(variables[idx][2])
        variables[i][2] = variables[idx][2]
        # print(variables[i][2], variables[idx][2])
        # exit(99)
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
          dict[variables[i][1]] = int(variables[i][2], 0)
    elif variables[i][0] == 'macrocalc':
      solution = 0
      try:
        solution = round(eval(variables[i][2], {}, dict))
      except NameError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 55)
      except SyntaxError:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 56)
      except AttributeError:
        errstr = "-> scope does not contain element"
        err(preserved, lines[i][0], errstr, 57)
      except TypeError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 58)
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
      if not isNumber(variables[i][3]):
        idx = findMulti(variables[i][3], variables, i - 1, 1)
        if idx == -1 or idx >= i:
          for j in range(len(preserved)):
            if variables[i][2] in preserved[j][1]:
              errstr = "-> undefined assignment \'{}\'".format(variables[i][3])
              err(preserved, preserved[j][0], errstr, 59)
        elif variables[idx][0] != 'macro' and variables[idx][0] != 'macrocalc':
          for j in range(len(preserved)):
            if variables[i][2] in preserved[j][1]:
              errstr = "-> const variables only accept macro or literal assigment"
              err(preserved, preserved[j][0], errstr, 60)
        # print(len(variables[i]), len(variables[idx]))
        # print(variables[i], variables[idx])
        variables[i][3] = variables[idx][2]
    elif variables[i][0] == 'constcalc':
      solution = 0
      try:
        # print(variables[i])
        # print(dict)
        solution = round(eval(variables[i][3], {}, dict))
      except NameError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 61)
      except SyntaxError:
        errstr = "-> invalid syntax"
        err(preserved, lines[i][0], errstr, 62)
      except AttributeError:
        errstr = "-> scope does not contain element"
        err(preserved, lines[i][0], errstr, 63)
      except TypeError:
        errstr = "-> undefined assignment"
        err(preserved, lines[i][0], errstr, 64)
      variables[i][3] = solution
  return variables


def scope(lines, preserved, infile):
  var = re.compile('((?<=[^A-z_0-9\\./])|^)([A-z_][A-z_0-9]*)((?=[^A-z_0-9\\.])|$)')
  ['sysvar', 'STATUS', '0'],
  ['sysvar', 'STACK', '2'],
  ['sysvar', 'UART', '3'],
  ['sysvar', 'GPIO', '4'],
  ['sysvar', 'GPIO_DIR', '5'],
  ['macro', 'TX_EMPTY', '512'],
  ['macro', 'TX_FULL', '256'],
  ['macro', 'RX_EMPTY', '2048'],
  ['macro', 'RX_FULL', '1024'],
  keywords = [
    'nop', 'ldr', 'str', 'lpt',
    'spt', 'cmp', 'add', 'sub',
    'mul', 'div', 'mod', 'and',
    'or',  'xor', 'not', 'lsl',
    'lsr', 'psh', 'pop', 'pek',
    'jmp', 'jsr', 'rts', 'joc',
    'jsc', 'rsc',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'pre', 'ram', 'rom', 'gpu',
    'def', 'var', 'const',
    'zero', 'carry', 'negative',
    'equal', 'greater', 'less',
    'UART', 'STACK', 'STATUS',
    'GPIO', 'GPIO_DIR', 'TX_EMPTY',
    'TX_FULL', 'RX_EMPTY', 'RX_FULL'
  ]
  for i in range(len(lines)):
    file = lines[i][0].split()[0]
    if file != infile[:-4]:
      # print(lines[i][1])
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
        err(preserved, lines[i][0], "-> dangling string", 65)
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
      #null terminated:
      lines[i][1] = lines[i][1][:currentIndex] + '0 ' + lines[i][1][currentIndex + 1:]
      lines[i][1] = repchr(lines[i][1], '}', currentIndex + 2)


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
  print("\nError in file \'{}.cor\' at line {}:".format(key.split()[0], key.split()[1]))
  error = ''
  for line in lines:
    if key == line[0]:
      error = line[1]
      break
  print("  {}".format(error.strip(' \n')))
  # it's possible this may instroduce errors in strings and stuff
  # consider sanitizing the input a bit more and accounting for strings TODO
  if key.split()[0] + '.' in message:
    message = message.replace(key.split()[0] + '.', '')
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

def expand(lines, infile, prefix):
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
            err(lines, lines[index][0], "-> recursive import call", 66);
          elif name in imported:
            err(lines, lines[index][0], "-> file already imported", 67);

          imported.append(name)
          tokens = lines[index][1].split()
          tempname = name[:-4]
          if len(tokens) > 2 and tokens[2] == 'as':
            if len(tokens) != 4:
              err(lines, lines[index][0], "-> invalid import syntax", 68);
            tempname = tokens[3]
          templine = lines[index]
          lines.pop(index)
          try:
            with open(prefix + name, 'r') as file:
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
