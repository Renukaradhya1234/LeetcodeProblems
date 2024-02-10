start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))

disarium = []
while start <= end :
    temp, sum = start, 0
    
    while temp > 0 :
        sum = sum + ((temp % 10) ** len(str(temp)))
        temp //= 10
    if start == sum :
        disarium.append(start)
    
    start += 1
print(disarium)