import re
from sys import argv
import assemblyutils as ass

# let's try to minimize the amount of loops

def main():

  infile = ''
  outfile = 'out.vus'
  if len(argv) < 2:
    print('Error: no input file provided')
    exit()
  elif len(argv) == 3:
    outfile = argv[2]
  infile = argv[1]
  if '.cor' not in infile:
    print('Error: input file must be of type .cor')
    exit()

  lines = []
  with open(infile, 'r') as file:
    for numLines, line in enumerate(file):
      lines.append(['{} {}'.format(infile[:-4], numLines + 1), line.strip(" \n")])

  ass.expand(lines, infile)
  ass.clean(lines)
  # preserving 'lines' for error reporting
  assembly = ass.copy2d(lines)
  ass.convertStrings(assembly, lines)
  # code = []
  # code.append(ass.encodeInstPass1(assembly[0][1], lines, 0))
  ass.scope(assembly, lines, infile)
  dict = {}
  vars = ass.convertVariables(assembly, lines, infile, dict)
  ass.cleanvars(assembly, lines)
  ass.reorderInstructions(assembly, infile)
  ass.addLabels(assembly, vars, lines)
  code = ass.encode(assembly, vars, lines, dict)
  ass.write(code, outfile)

  for line in assembly:
    print(line)
  print()
  for var in vars:
    print(var)
  print()
  i = 0
  for line in code:
    print('Word {}:'.format(i))
    i += 1
    ass.printWord(line)
  # print("Code:")
  # for element in code:
  #   print(element)




if __name__ == '__main__':
  main()
