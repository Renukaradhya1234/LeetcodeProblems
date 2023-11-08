'''
  Write a program to check armstrong number in given range
'''

start = int(input('Enter the starting number: '))
end = int(input('Enter the ending number: '))

armstrong = []

while start < end:
  start1 = start
  temp = 0
  length = len(str(start))
  while start1 > 0:
    temp = temp + ((start1%10) ** length)
    start1 //= 10
  if start == temp:
    armstrong.append(start)
  start += 1
print(f'list of armstrong numbers is {armstrong}')
