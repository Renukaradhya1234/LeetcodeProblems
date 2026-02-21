int isValidPrimeNumber(int number) {
    switch (number) {
        case 2 :
        case 3 :
        case 5 :
        case 7 :
        case 11 :
        case 13 :
        case 17 :
        case 19 :
            return 1;
    }
    return 0;
}

int countBitSet(int number) {
    int count = 0;

    while (number > 0) {
        number = number & (number-1);
        count++;
    }

    return count;
}

int countPrimeSetBits(int left, int right) {
    /// count the number 1s in binary....
    /// list the prime number in range 1, 32 --- 2, 3, 5, 7, 11, 13, 17 or 19.

    int result = 0;

    while (left <= right) {
        int count_bit = countBitSet(left);
        result += isValidPrimeNumber(count_bit);
        left++;
    }

    return result;
}