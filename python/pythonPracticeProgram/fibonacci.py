num = int(input("Enter the number: "))

a, b, fib = 0, 1, []

if num > 0 :
    if num == 1 :
        fib.append(a)
        print(fib)
    else :
        i = 2 
        fib.append(a)
        fib.append(b)
        while i < num :
            c = a + b
            fib.append(c)

            a = b
            b = c
            
            i += 1
        print(fib)
else :
    print("Please enter the number greater then zero .....")