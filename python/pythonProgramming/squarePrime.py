def main(start, end):
  return list( map(lambda x: x**2 , filter(lambda num: not(bool( [ i for i in range(2, num) if num % i == 0 ])) if num != 2 else False, range(start, end+1)) ) )
