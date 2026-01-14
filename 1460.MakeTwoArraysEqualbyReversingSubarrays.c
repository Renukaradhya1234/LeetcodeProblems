#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int number_buffer[1001] = {0};
    for (int index = 0; index < targetSize; index++) {
        number_buffer[ target[index] ]++;
    }

    int sorted_number_index = 0;
    for (int index = 0; index < 1001; index++) {
        for (int count = number_buffer[index]; count > 0; count--) {
            target[sorted_number_index++] = index;
        }
        number_buffer[index] = 0;
    }

    for (int index = 0; index < arrSize; index++) {
        number_buffer[ arr[index] ]++;
    }

    sorted_number_index = 0;

    for (int index = 0; index < 1001; index++) {
        for (int count = number_buffer[index]; count > 0; count--) {
            arr[sorted_number_index++] = index;
        }
    }

    bool can_be_equal = true;

    for (int index = 0; index < targetSize; index++) {
        if (target[index] != arr[index]) {
            can_be_equal = false;
            break;
        }
    }

    return can_be_equal;
}