num = int(input("Enter the number: "))
temp = num

if len(str(num)) > 2 :
    ld, md = 0, 0
    while temp > 0 :
        if len(str(temp)) == 1 or len(str(temp)) == len(str(num)) :
            ld += (temp % 10)
        else :
            md += (temp % 10)
        temp //= 10
    if ld == md :
        print("Xylem number....")
    else :
        print("Pholem number.....")
    
else :
    print("Please enter more than 2 digits....")
