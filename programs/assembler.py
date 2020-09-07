import re
from sys import argv
import assemblyutils as ass

# let's try to minimize the amount of loops

def main():

  infile = ''
  outfile = ''
  promName = ''
  dromName = ''
  if len(argv) < 2:
    print('Error: no input or output file provided')
    exit(1)
  elif len(argv) < 3:
    print('Error: no output file provided')
    exit(1)
  elif len(argv) < 5:
    print("give me more agruments dangit")
    exit(1)
  elif len(argv) == 5:
    outfile = argv[2]
    promName = argv[3]
    dromName = argv[4]
  infile = argv[1]
  if '.cor' not in infile[-4:]:
    print('Error: input file must be of type .cor')
    exit(1)
  if '.vus' not in outfile[-4:]:
    print('Error: output file must be of type .vus')
    exit(1)
  if '.v' not in promName[-2:]:
    print('Error: expecting verilog output file')
    exit(1)

  prefix = ''
  for i in range(len(infile) - 1, -1, -1):
      if infile[i] == '/':
          prefix = infile[:i + 1]
          infile = infile[i + 1:]
          break

  lines = []
  with open(prefix + infile, 'r') as file:

    for numLines, line in enumerate(file):
      lines.append(['{} {}'.format(infile[:-4], numLines + 1), line.strip(" \n")])

  ass.expand(lines, infile, prefix)
  ass.clean(lines)
  # print(lines)
  # preserving 'lines' for error reporting
  assembly = ass.copy2d(lines)
  ass.convertStrings(assembly, lines)
  # code = []
  # code.append(ass.encodeInstPass1(assembly[0][1], lines, 0))
  ass.scope(assembly, lines, infile)
  ass.expandArrays(assembly, lines)
  # for line in assembly:
  #   print(line)
  dict = {}
  vars = ass.convertVariables(assembly, lines, infile, dict)
  # print(vars)
  ass.cleanvars(assembly, lines)
  if len(assembly) == 0:
    print('Error: the provided file \'{}\' contains no executable code'.format(infile))
    exit(1)

  ass.reorderInstructions(assembly, infile)
  ass.addLabels(assembly, vars, lines)

  code = ass.encode(assembly, vars, lines, dict)
  ass.write(code, outfile) # binary

  ass.writeVerilogPROM(code, promName) # verilog inferred rom
  ass.writeVerilogDROM(vars, dromName)

  for line in assembly:
    print(line)
  print()
  # for var in vars:
  #   print(var)
  # print()
  i = 0
  for line in code:
    print('Word {}:'.format(i))
    i += 1
    ass.printWord(line)

  for var in vars:
    print(var)

  # for element in vars:
  #   if 'const' in element[0]:
  #     print('Address {}:'.format(int(element[1])))
  #     ass.printDromWord(int(element[3]))
  # print("Code:")
  # for element in code:
  #   print(element)




if __name__ == '__main__':
  main()
