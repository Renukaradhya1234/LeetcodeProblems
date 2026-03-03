/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* two_sum_indices = (int*)malloc(2*sizeof(int));
    if (two_sum_indices == NULL) {
        *returnSize = 0;
        return two_sum_indices;
    }
    *returnSize = 2;
    int start_index = 0;
    int end_index = numbersSize-1;

    while (start_index < end_index) {
        int sum = numbers[start_index] + numbers[end_index];
        if (sum == target) {
            two_sum_indices[0] = start_index+1;
            two_sum_indices[1] = end_index+1;
            break;
        }
        if (sum > target) {
            start_index++;
        } else {
            end_index--;
        }
    }

    return two_sum_indices;
}