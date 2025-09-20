/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    unsigned int max_number = numsSize;
    int* number_buffer = calloc(numsSize, sizeof(int));
    for (unsigned int index = 0; index < numsSize; index++) {
        unsigned int number_index = nums[index] - 1;
        if (number_buffer[number_index] == 0) {
            number_buffer[number_index] = 1;
            max_number--;
        }
    }

    *returnSize = max_number;
    int* missing_numbers = (int*)malloc(max_number*sizeof(int));
    unsigned int missing_numbers_index = 0;
    for (unsigned int index = 0; index < numsSize; index++) {
        if (number_buffer[index] == 0) {
            missing_numbers[missing_numbers_index] = index+1;
            missing_numbers_index++;
        }
    }
    free(number_buffer);
    return missing_numbers;
}