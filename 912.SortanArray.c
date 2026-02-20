#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

void mergeSort(int* original_array, int start_index, int end_index, int* temp_array) {
    if (start_index >= end_index) {
        return;
    }
    int mid_index = start_index + (end_index-start_index)/2;
    mergeSort(original_array, start_index, mid_index, temp_array);
    mergeSort(original_array, mid_index+1, end_index, temp_array);
    int temp_start_index = start_index;
    int temp_mid_index = mid_index+1;
    int index = start_index;
    while (temp_start_index <= mid_index && temp_mid_index <= end_index) {
        if (original_array[temp_start_index] < original_array[temp_mid_index]) {
            temp_array[index++] = original_array[temp_start_index++];
        } else {
            temp_array[index++] = original_array[temp_mid_index++];
        }
    }

    while (temp_start_index <= mid_index) {
        temp_array[index++] = original_array[temp_start_index++];
    }

    while (temp_mid_index <= end_index) {
        temp_array[index++] = original_array[temp_mid_index++];
    }

    for (int index = start_index; index <= end_index; index++) {
        original_array[index] = temp_array[index];
    }

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* sorted_array = (int*)malloc(numsSize*sizeof(int));
    if (sorted_array == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    for (int index = 0; index < numsSize; index++) {
        int current_data = nums[index];
        max_value = MAX(current_data, max_value);
        min_value = MIN(current_data, min_value);
    }

    int total_range = (max_value - min_value) + 1;
    if (total_range <= 2*numsSize) {
        int* number_buffer = (int*)calloc(total_range, sizeof(int));
        if (number_buffer == NULL) {
            // apply merge sort if memory fails....
            for (int index = 0; index < numsSize; index++) {
                sorted_array[index] = nums[index];
            }

            mergeSort(sorted_array, 0, numsSize-1, nums);
        } else {
            /// if memory allocated then perform counting sort...
            for (int index = 0; index < numsSize; index++) {
                int current_data = nums[index];
                number_buffer[current_data-min_value]++;
            }

            int start_index = 0;
            for (int index = 0; index < total_range; index++) {
                for (int count = number_buffer[index]; count > 0; count--) {
                    sorted_array[start_index++] = index+min_value;
                }
            }

            free(number_buffer);
        }
    } else {
        // apply merge sort if range is greater...
        for (int index = 0; index < numsSize; index++) {
            sorted_array[index] = nums[index];
        }

        mergeSort(sorted_array, 0, numsSize-1, nums);
    }

    *returnSize = numsSize;
    return sorted_array;
}