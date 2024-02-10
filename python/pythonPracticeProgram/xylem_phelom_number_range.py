start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))
xylem, pholem = [], []

while start <= end :
    temp, ld, md = start, 0, 0
    while temp > 0 :
        if len(str(temp)) == 1 or len(str(temp)) == len(str(start)) :
            ld += (temp % 10)
        else :
            md += (temp % 10)
        temp //= 10
    if ld == md :
        xylem.append(start)
    else :
        pholem.append(start)
    start += 1
print("xylem: ",xylem)
print("Pholem: ", pholem) 