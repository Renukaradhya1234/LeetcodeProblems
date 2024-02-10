start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))

perfect = []

while start <= end :
    i = 1
    res = 0
    while i < start :
        if start % i == 0 : 
            res += i
        i += 1

    if start == res:
        perfect.append(start)

    start += 1
print(perfect)