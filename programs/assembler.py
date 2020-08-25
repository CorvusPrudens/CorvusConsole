import re
from sys import argv
import assemblyutils as ass

# let's try to minimize the amount of loops

def main():

  infile = ''
  outfile = ''
  verifile = ''
  if len(argv) < 2:
    print('Error: no input or output file provided')
    exit(1)
  elif len(argv) < 3:
    print('Error: no output file provided')
    exit(1)
  elif len(argv) == 4:
    outfile = argv[2]
    verifile = argv[3]
  infile = argv[1]
  if '.cor' not in infile[-4:]:
    print('Error: input file must be of type .cor')
    exit(1)
  if '.vus' not in outfile[-4:]:
    print('Error: output file must be of type .vus')
    exit(1)
  if '.v' not in verifile[-2:]:
    print('Error: expecting verilog output file')
    exit(1)

  lines = []
  with open(infile, 'r') as file:
    for numLines, line in enumerate(file):
      lines.append(['{} {}'.format(infile[:-4], numLines + 1), line.strip(" \n")])

  ass.expand(lines, infile)
  ass.clean(lines)
  print(lines)
  # preserving 'lines' for error reporting
  assembly = ass.copy2d(lines)
  ass.convertStrings(assembly, lines)
  # code = []
  # code.append(ass.encodeInstPass1(assembly[0][1], lines, 0))
  ass.scope(assembly, lines, infile)
  dict = {}
  vars = ass.convertVariables(assembly, lines, infile, dict)
  ass.cleanvars(assembly, lines)
  if len(assembly) == 0:
    print('Error: the provided file \'{}\' contains no executable code'.format(infile))
    exit(1)
  ass.reorderInstructions(assembly, infile)
  ass.addLabels(assembly, vars, lines)
  code = ass.encode(assembly, vars, lines, dict)
  ass.write(code, outfile) # binary

  ass.writeVerilog(code, verifile) # verilog inferred rom

  for line in assembly:
    print(line)
  print()
  for var in vars:
    print(var)
  print()
  i = 0
  # for line in code:
  #   print('Word {}:'.format(i))
  #   i += 1
  #   ass.printWord(line)
  # print("Code:")
  # for element in code:
  #   print(element)




if __name__ == '__main__':
  main()
