#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    int sorted_number[500] = {0};
    int sorted_number_index = 0;

    int number_buffer[101] = {0};
    int total_sum = 0;
    for (int index = 0; index < numsSize; index++) {
        number_buffer[ nums[index] ]++;
        total_sum += nums[index];
    }

    for (int index = 100; index >= 0; index--) {
        for (int count = number_buffer[index]; count > 0; count--) {
            sorted_number[sorted_number_index++] = index;
        }
    }

    int total_size = 0;
    int largest_num_sum = 0;
    for (int index = 0; index < numsSize; index++) {
        largest_num_sum += sorted_number[index];
        total_sum -= sorted_number[index];
        total_size++;
        if (largest_num_sum > total_sum) {
            break;
        }
    }

    int* largest_numbers = (int*)malloc(total_size*sizeof(int));
    if (largest_numbers != NULL) {
        *returnSize = total_size;
        for (int index = 0; index < total_size; index++) {
            largest_numbers[index] = sorted_number[index];
        }
    }
    return largest_numbers;
}