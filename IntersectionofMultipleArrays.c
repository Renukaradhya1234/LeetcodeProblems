#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int buffer_array[1001] = { 0 };
    int total_size = 0;
    for (int outer_index = 0; outer_index < numsSize; outer_index++) {
        for (int inner_index = 0; inner_index < numsColSize[outer_index]; inner_index++) {
            buffer_array[ nums[outer_index][inner_index] ]++;
            if (buffer_array[ nums[outer_index][inner_index] ] == numsSize) {
                total_size++;
            }
        }
    }

    int* intersection_elements = (int*)malloc(total_size*sizeof(int));
    if (intersection_elements != NULL) {
        int index = 0;
        *returnSize = total_size;
        for (int array_index = 0; array_index < 1001; array_index++) {
            if (buffer_array[array_index] == numsSize) {
                intersection_elements[index] = array_index;
                index++;
            }
        }
    }

    return intersection_elements;
}