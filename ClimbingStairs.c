int climbStairs(int n) {
    int result = 1;
    if (n > 1) {
        int first_number = 1;
        int second_number = 1;
        for (int number = 1; number < n; number++) {
            result = first_number + second_number;
            first_number = second_number;
            second_number = result;
        }
    }
    return result;
}