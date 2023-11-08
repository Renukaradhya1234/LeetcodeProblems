''' WAP to check whether a person is eligible for voting or not '''

def check():
  print('Eligible...') if int(input('Enter the age: ')) > 18 else print('Not eligible...')
