'''
  input : 'we are the best'
  output : {'we': 'wwee', 'are': 'aaree', 'the': 'tthee', 'best': 'bbestt'}
'''

print({key: key[0]+key+key[-1] for key in input('Enter the string: ').split()})
