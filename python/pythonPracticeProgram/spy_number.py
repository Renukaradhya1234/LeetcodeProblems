num = int(input("Enter the number: "))
add, mul = 0, 1
while num > 0 :
    add += (num % 10)
    mul *= (num % 10)
    num //= 10

if add == mul :
    print("Spy number....")
else :
    print("Not Spy number....")