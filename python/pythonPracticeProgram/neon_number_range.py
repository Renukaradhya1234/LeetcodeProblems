start = int(input("Enter the start number: "))
end = int(input("Enter the ending number: "))
neon = []

while start <= end :
    sq = start ** 2
    add = 0
    while sq > 0 :
        add += (sq % 10)
        sq //= 10
    if add == start :
        neon.append(start)
    start += 1
print(neon)