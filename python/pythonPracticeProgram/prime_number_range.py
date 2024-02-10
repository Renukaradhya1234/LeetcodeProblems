start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))

prime = []

while start < end:
    i = 2
    count = 0
    while i < start:
        if start % i == 0:
            count += 1
        i += 1
        
    if count == 0:
        prime.append(start)
    
    start += 1

print(prime)
