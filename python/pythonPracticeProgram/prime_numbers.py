num = int(input("Enter the number: "))

count = 0
i = 2
while i < num:
    if num % i == 0:
        count += 1
    i += 1

if count > 0:
    print("Not a prime number....")
else:
    print("Prime number...")