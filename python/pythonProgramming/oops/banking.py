class Account:
  def __init__(self, account_number, account_holder, balance = 0):
    self.account_number = account_number
    self.account_holder = account_holder
    self.balance = balance
  def deposit( self, amount):
    self.balance += amount
    print(f'Amount {amount} deposited. current balance: {self.balance}')
  def withdraw( self, amount):
    if self.balance >= amount:
      self.balance -= amount
      print(f' Amount {amount} withdrawn. current balance: {self.balance} ')
    else:
      print('Insufficient balance')
  def display( self):
    print(f'Account number: {self.account_number}')
    print(f'Account holder: {self.account_holder}')
    print(f'Balance: {self.balance}')

class SavingsAccount(Account):
  def __init__(self, account_number, account_holder, balance = 0.0, interest_rate = 0.0):
    super().__init__(account_number, account_holder, balance)
    self.interest_rate = interest_rate
  def calculate_interest(self):
    interest = self.balance * self.interest_rate
    self.balance += interest
    print(f'Interest calculated: {interest}')
    print(f'Updated balance: {self.balance}')
    
