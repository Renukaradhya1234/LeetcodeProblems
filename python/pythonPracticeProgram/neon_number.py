num = int(input("Enter the number: "))
sq, add = num ** 2, 0 
while sq > 0 :
    add += (sq % 10)
    sq //= 10
if add == num :
    print("Neon number....")
else :
    print("Not Neon number....")