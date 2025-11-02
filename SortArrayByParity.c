#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* output = (int*)malloc(numsSize*sizeof(int));

    if (output != NULL) {
        int output_index = 0;
        *returnSize = numsSize;
        for (int index = 0; index < numsSize; index++) {
            if (nums[index] % 2 == 0) {
                output[output_index++] = nums[index];
            }
        }

        for (int index = 0; index < numsSize; index++) {
            if (nums[index] % 2 != 0) {
                output[output_index++] = nums[index];
            }
        }
    }

    return output;
}