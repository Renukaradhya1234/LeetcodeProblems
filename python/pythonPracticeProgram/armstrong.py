num = int(input("Enter the number: "))
num1 = num
length = len(str(num))
arm = 0
i = 0
while num > 0:
    arm = arm + ((num % 10) ** length )
    num //= 10

if num1 == arm:
    print("Armstrong...")
else:
    print("not Armstrong...")