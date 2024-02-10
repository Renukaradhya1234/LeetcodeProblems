num = int(input("Enter the number: "))

fact, i = 1, 1
while i <= num :
    fact = fact * i
    i += 1
print(fact)