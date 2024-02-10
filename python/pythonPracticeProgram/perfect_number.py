num = int(input("Enter the number: "))

res = 0
i = 1

while i < num:
    if num % i == 0: 
        res += i
    i += 1
if num == res:
    print("perfect number...")
else:
    print("Not perfect number...")