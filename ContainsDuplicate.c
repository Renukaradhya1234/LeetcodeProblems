#include <stdbool.h>

void swapElements(int* array, int first_index, int second_index) {
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void setPivotValueToLast(int* array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    
    /// finding the hightest value index....
    if (array[start_index] > array[mid_index] && array[start_index] > array[end_index]) {
        highest_index = start_index;
    } else if (array[mid_index] > array[start_index] && array[mid_index] > array[end_index]) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }
    
    
    if (start_index == highest_index) {
        if (array[mid_index] > array[end_index]) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (array[start_index] > array[end_index]) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (array[start_index] > array[mid_index]) {
            mean_index = start_index;
        } else {
            mean_index = mid_index;
        }
    }

    if (end_index != mean_index) {
        /// if mean value not in end of the partition...
        swapElements(array, mean_index, end_index);
    }
    
}

bool quickSortWithChecker(int* array, int start_index, int end_index) {
    bool duplicate_present = false;
    if (start_index < end_index) {
        setPivotValueToLast(array, start_index, end_index);
        int pivot_value = array[end_index];
        int pivot_index = start_index-1;
        for (int index = start_index; index < end_index; index++) {
            if (array[index] < pivot_value) {
                swapElements(array, ++pivot_index, index);
            }
        }
        swapElements(array, ++pivot_index, end_index);
        duplicate_present = quickSortWithChecker(array, pivot_index+1, end_index); /// right half array....
        
        if (!duplicate_present) {
            if (pivot_index+1 <= end_index && array[pivot_index] == array[pivot_index+1]) {
                duplicate_present = true;
            } else {
                duplicate_present = quickSortWithChecker(array, start_index, pivot_index-1); /// left half array....
            }
        }
    }
    return duplicate_present;
}

bool containsDuplicate(int* nums, int numsSize) {
    return quickSortWithChecker(nums, 0, numsSize-1);
}