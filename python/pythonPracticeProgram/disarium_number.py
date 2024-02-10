num = int(input("Enter the number: "))
temp, sum = num, 0

while temp > 0 :
    sum = sum + ((temp % 10) ** len(str(temp)))
    temp //= 10

if num == sum :
    print("disarium number....")
else :
    print("Not disarium number....")