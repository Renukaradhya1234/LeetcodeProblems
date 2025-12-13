#include <stdlib.h>

int convertReverseBinaryDigits(int number) {
    int binary_buffer[32] = {0};
    int binary_index = 0;
    while (number > 0) {
        binary_buffer[binary_index++] = number % 2;
        number /= 2;
    }

    int binary_reverse = 0;
    int binary_power = 1;
    for (int start_index = binary_index-1; start_index >= 0; start_index--) {
        binary_reverse += binary_buffer[start_index] * binary_power;
        binary_power *= 2;
    }
    return binary_reverse;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByReflection(int* nums, int numsSize, int* returnSize) {
    int number_buffer[100] = { 0 };
    *returnSize = numsSize;
    for (int index = 0; index < numsSize; index++) {
        number_buffer[index] = convertReverseBinaryDigits(nums[index]);
    }

    for (int index = 0; index < numsSize; index++) {
        int value = nums[index];
        int current_index = index-1;

        int binary_reverse = number_buffer[index];
        while (current_index >= 0) {
            int current_value = nums[current_index];
            int current_binary_reverse = number_buffer[current_index];

            if (binary_reverse < current_binary_reverse) {
                nums[current_index+1] = nums[current_index];
                number_buffer[current_index+1] = number_buffer[current_index];
            } else if (binary_reverse == current_binary_reverse && value < current_value) {
                nums[current_index+1] = nums[current_index];
                number_buffer[current_index+1] = number_buffer[current_index];
            } else {
                break;
            }

            current_index--;
        }

        nums[current_index+1] = value;
        number_buffer[current_index+1] = binary_reverse;
    }

    return nums;
}