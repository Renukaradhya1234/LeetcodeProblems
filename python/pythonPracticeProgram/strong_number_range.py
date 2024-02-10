start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))
strong = []

while start <= end :
    temp = start
    sum = 0
    while temp > 0 :
        ld = temp % 10
        i, fact = 1, 1
        while i <= ld :
            fact *= i
            i += 1
        sum += fact
        temp //= 10
    
    if start == sum :
        strong.append(start)
    start += 1

print(strong)