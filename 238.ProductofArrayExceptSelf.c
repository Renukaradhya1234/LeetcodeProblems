#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize*sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int prefix_product = 1;
    for (int index = 0; index < numsSize; index++) {
        result[index] = prefix_product;
        prefix_product *= nums[index];
    }

    int suffix_product = 1;
    for (int index = numsSize-1; index >= 0; index--) {
        result[index] *= suffix_product;
        suffix_product *= nums[index];
    }
    
    *returnSize = numsSize;
    return result;
}