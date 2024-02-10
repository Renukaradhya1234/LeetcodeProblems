start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))
spy = []

while start < end :
    add, mul, temp = 0, 1, start
    while temp > 0 :
        add += (temp % 10)
        mul *= (temp % 10)
        temp //= 10
    
    if add == mul :
        spy.append(start)
    start += 1
print(spy)