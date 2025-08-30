#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    bool result = false;
    unsigned int last_digit = num % 10;
    if (last_digit == 0 || last_digit == 1 || last_digit == 4 || last_digit == 9 || last_digit == 5 || last_digit == 6) {
        int start_number = 0;
        unsigned int max_square_root = 46340; // max square root number, that can store in 32 bits...
        unsigned int end_number = (num < max_square_root) ? num : max_square_root;
        unsigned int mid_number = 0;
        unsigned int square = 0;
        while (start_number <= end_number) {
            mid_number = start_number + (end_number-start_number) / 2;
            square = mid_number * mid_number;
            if (square == num) {
                result = true;
                break;
            } else if (square > num) {
                end_number = mid_number-1;
            } else {
                start_number = mid_number+1;
            }
        }
    }

    return result;
}

int main() {

    unsigned int number = 2147395600;
    bool is_perfect_square = isPerfectSquare(number);
    printf("result:- %d\n", is_perfect_square);
    return 0;
}