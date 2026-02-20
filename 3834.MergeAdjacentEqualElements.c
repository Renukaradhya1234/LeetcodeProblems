#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* mergeAdjacent(int* nums, int numsSize, int* returnSize) {
    long long* merge_adjacent = (long long*)malloc(numsSize*sizeof(long long));
    if (merge_adjacent == NULL) {
        *returnSize = 0;
        return merge_adjacent;
    }

    merge_adjacent[0] = nums[0];
    int last_index = 0;
    for (int index = 1; index < numsSize; index++) {
        long long current_data = nums[index];
        if (merge_adjacent[last_index] == current_data) {
            /// top == current value..
            long long updated_value = current_data;
            while (last_index >= 0) {   
                if (merge_adjacent[last_index] != updated_value) {
                    break;
                } else {
                    updated_value += merge_adjacent[last_index--];
                }
            }
            merge_adjacent[++last_index] = updated_value;
        } else {
            merge_adjacent[++last_index] = current_data;
        }
    }
    *returnSize = ++last_index;
    return merge_adjacent;
}