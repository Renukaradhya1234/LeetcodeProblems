num = int(input("Enter the number: "))

while num > 9:
    temp = 0
    while num > 0:
        temp = temp + ((num % 10)** 2)
        num //= 10
    num = temp

if num == 1 or num == 7 :
    print("Happy....", num)
else:
    print("Not Happy....",num)