#include <stdlib.h>>

int* integerToBinary(int number) {
    int* result = calloc(32, sizeof(int));
    unsigned int index = 0;

    while (number > 0) {
        result[index++] = number % 2;
        number /= 2;
    }
    return result;
}

int hammingDistance(int x, int y) {
    int* x_binary = integerToBinary(x);
    int* y_binary = integerToBinary(y);

    unsigned int count = 0;

    for (unsigned int index = 0; index < 32; index++) {
        if (x_binary[index] != y_binary[index]) {
            count++;
        }
    }

    /// free the allocated the memory...
    free(x_binary);
    free(y_binary);

    return count;
}