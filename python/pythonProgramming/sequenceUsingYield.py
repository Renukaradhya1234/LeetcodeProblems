def main(num):
  for i in range( 0 if num % 2 == 0 else 1, num, 2):
    yield i

print(list(main(10)))
print(list(main(11)))
