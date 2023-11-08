'''
  a = [ 'python', 'is', 'easy', 'but' ]
  b = 10
  output = [ 'python__is' , 'easy___but' ] 
  Hint : output string length should be b
'''

def main(a, b):
  out = []
  for i in range(0, len(a), 2):
    count = b - (len(a[i])+len(a[i+1]))
    out.append( (a[i] + ( '_'*count ) + a[i+1]) )
  return out
