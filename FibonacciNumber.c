int fib(int n){
    int result = 0;
    if (n >= 1) {
        if (n == 1) {
            result = 1;
        } else {
            unsigned int first_number = 0;
            unsigned int second_number = 1;

            for(int index=2; index <= n; index++) {
                result = first_number+second_number;
                first_number = second_number;
                second_number = result;
            }
        }
    }

    return result;
}