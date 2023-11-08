'''
  Write a program to find greatest number amoung four number without using logical operator
'''

a = int(input('Enter the number1: '))
b = int(input('Enter the number2: '))
c = int(input('Enter the number3: '))
d = int(input('Enter the number4: '))

if a > b:
  if a > c:
    if a > d:
      print(f'greatest among four number is a: {a}')
    else:
      print(f'greatest among four numbers is d: {d}')
  elif  c > d:
    print(f'greatest among four numbers is c: {c}')
  else:
    print(f'greatest among four numbers is d: {d}')
elif b > c:
  if b > d:
    print(f'greatest among four numbers is b: {b}')
  else:
    print(f'greatest among four numbers is d: {d}')
elif c > d:
  print(f'greatest amoung four numbers is c: {c}')
else:
  print(f'greatest amoung four numbers is d: {d}')
