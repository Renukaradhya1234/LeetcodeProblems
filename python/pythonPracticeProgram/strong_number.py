num = int(input("Enter the number: "))
temp, res = num, 0

while num > 0 :
    ld = num % 10
    i, fact = 1, 1
    while i <= ld :
        fact *= i
        i += 1
    res += fact 
    num //= 10
if temp == res :
    print("Strong number....")
else :
    print("Not strong number....")