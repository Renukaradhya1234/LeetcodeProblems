''' WAP to calculate a oldest one amoung 4 people '''
def main():
  num1, num2, num3, num4 = int(input('Enter the age1: ')), int(input('Enter the age2: ')), int(input('Enter the age3: ')), int(input('Enter the age4: '))
  print(num1) if num1>num2 and num1>num3 and num1>num4 else print(num2) if num2>num3 and num2>num4 else print(num3) if num3>num4 else print(num4)
