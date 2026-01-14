#include <stdbool.h>

void swap(int* array, int first_index, int second_index) {
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void setPivotValueToLast(int* array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    int start_index_value = array[start_index];
    int mid_index_value = array[mid_index];
    int end_index_value = array[end_index];
    
    /// finding the hightest value index....
    if (start_index_value > mid_index_value && start_index_value > end_index_value) {
        highest_index = start_index;
    } else if (mid_index_value > start_index_value && mid_index_value > end_index_value) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }
    
    
    if (start_index == highest_index) {
        if (mid_index_value > end_index_value) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (start_index_value > end_index_value) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (start_index_value > mid_index_value) {
            mean_index = start_index;
        } else {
            mean_index = mid_index;
        }
    }

    if (end_index != mean_index) {
        /// if mean value not in end of the partition...
        swap(array, mean_index, end_index);
    }
    
}


void quickSort(int* array, int start_index, int end_index) {
    if (start_index < end_index) {
        setPivotValueToLast(array, start_index, end_index);
        int pivot_index = start_index-1;
        int pivot_value = array[end_index];

        for (int index = start_index; index < end_index; index++) {
            /// value is greater then pivot swift after the pivot index.
            if (array[index] > pivot_value) {
                swap(array, ++pivot_index, index);
            }
        }
        swap(array, ++pivot_index, end_index);
        quickSort(array, start_index, pivot_index-1);
        quickSort(array, pivot_index+1, end_index);
    }
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int total_iteration = arrSize-1;
    quickSort(arr, 0, total_iteration);
    int difference = arr[0] - arr[1];
    bool can_make_arithmetic_progression = true;
    for (int index = 0; index < total_iteration; index++) {
        if (difference != arr[index]-arr[index+1]) {
            can_make_arithmetic_progression = false;
            break;
        }
    }
    return can_make_arithmetic_progression;
}