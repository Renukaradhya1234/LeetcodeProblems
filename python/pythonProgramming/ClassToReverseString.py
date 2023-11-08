'''
  Write class to reverse the string
'''

class String:
    def __init__(self, str_variable):
        self.variable = str_variable
    def reverse(self):
        return self.variable[::-1]

a = String('renu')
print(a.reverse())
