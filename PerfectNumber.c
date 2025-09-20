#include <stdbool.h>

bool checkPerfectNumber(int num) {
    unsigned int result = 0;
    for (unsigned int divisor = 1; divisor < num/2; divisor++) {
        if (num % divisor == 0) {
            result += divisor;
        }
    }
    return result == num;
}