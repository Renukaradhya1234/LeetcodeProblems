int reverse(int x){
    int reversed_digits = 0;

    while (x > 0) {
        int last_digits = x%10;
        x /= 10;
        if (reversed_digits > 214748364 || (reversed_digits == 214748364 && last_digits > 7)) {
            return 0;
        } 
        if (reversed_digits < -214748364 || (reversed_digits == -214748364 && reversed_digits > -8)) {
            return 0;
        }

        reversed_digits = reversed_digits*10 + last_digits;
    }

    return reversed_digits;
}