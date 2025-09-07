int power(int number, int exponent, int result) {
    for (int index = 0; index < exponent; index++) {
        result *= number;
    }

    return result;
}

int reverseBits(int n) {
    int binary_buffer[32];
    int index = 0;   

    while (n>0) {
        /// store the binary digits in reverse order...
        binary_buffer[index++] = n % 2;
        /// while loop updation...
        n /= 2;
    }

    unsigned int result = 0;
    int last_exponent = -1;
    int last_power_result = 1;
    while (index > 0) {
        index--;
        if (binary_buffer[index] == 1) {
            // find the power only for 1's 
            // we can use inbuilt function for finding the power.
            int exponent = 32 - (index+1);
            int temp_exponent = (last_exponent == -1) ? exponent : exponent - last_exponent;
            last_power_result = power(2, temp_exponent, last_power_result);
            last_exponent = exponent;
            result += last_power_result;
        }
    }
    return result;
}