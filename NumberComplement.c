int findComplement(int num) {
    unsigned int result = 0;
    unsigned int last_powered_number = 0;
    unsigned int binary_digit = 0;
    while (num > 0) {
        if (last_powered_number == 0) {
            last_powered_number = 1;
        } else {
            last_powered_number *= 2;
        }
        binary_digit = num % 2 == 0 ? 1 : 0;
        result += binary_digit * last_powered_number;

        // loop updation...
        num /= 2;
    }

    return result;
}