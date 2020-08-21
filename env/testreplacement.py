# import re
#
# variables = [
#     ['macro', 'imp.MACRO', '1']
#     ['var', 'x'],
#     ['macro', 'TEST', 'imp.MACRO']
#     ['macrocalc', 'MACRO', 'imp.MACRO'],
#     ['macrocalc', 'MACRO2', 'MACRO<<1'],
#     ['macrocalc', 'MACRO3', '20+MACRO2*2'],
#     ['const', 'always', '20+MACRO2*2'],
#     ['var', 'y'],
#     ['var', 'temp'],
# ]
#
# def err(lines, idx):
#   print('oops')
#
# def findMulti(str, arr, start, depth):
#   for i in range(start, -1, -1):
#     if str == arr[i][depth]:
#       return i
#   return -1
#
# def replaceVariables(input, varDict):
#   return round(eval(input, {}, varDict))
#
# for i in range(len(variables)):
#   if variables[i][0] == 'macro':
#     if not variables[i][2].isnumeric(): # macro defined by other macro
#       idx = findMulti(variables[i][2], variables, i - 1, 1)
#       if idx == -1:
#         err(None, i)
#         print("-> undefined assignment")
#         exit()
#       variables[i][2] = variables[idx][2]
#
#
#
#
# mod = type('mod', (object,), {})
# mod.var = 2
#
# input = 'mod.var + MACRO2+300*20/MACRO3'
# varDict = {'MACRO': 1, 'MACRO2': 2,'MACRO3': 300, 'mod': mod}
# print(replaceVariables(input, varDict))

# print(eval('MACRO<<1', {}, {'MACRO': 1}))
dict = {}
dict['boy'] = type('boy', (object,), {})
setattr(dict['boy'], 'fun', 20)
print(dict['boy'].fun)
