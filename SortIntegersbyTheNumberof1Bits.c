#include <stdlib.h>

struct bit_with_data {
    int data;
    int bit_count;
};

void swap(struct bit_with_data* array, int first_index, int second_index) {
    struct bit_with_data temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}


void setPivotValueToLast(struct bit_with_data* array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    int start_index_data = array[start_index].bit_count;
    int mid_index_data = array[mid_index].bit_count;
    int end_index_data = array[end_index].bit_count;
    
    /// finding the hightest value index....
    if (start_index_data > mid_index_data && start_index_data > end_index_data) {
        highest_index = start_index;
    } else if (mid_index_data > start_index_data && mid_index_data > end_index_data) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }
    
    
    if (start_index == highest_index) {
        if (mid_index_data > end_index_data) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (start_index_data > end_index_data) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (start_index_data > mid_index_data) {
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

void quickSort(struct bit_with_data* array, int start_index, int end_index) {
    if (start_index < end_index) {
        setPivotValueToLast(array, start_index, end_index);
        int pivot_index = start_index-1;
        int pivot_value = array[end_index].bit_count;
        int original_pivot_data = array[end_index].data;

        for (int index = start_index; index < end_index; index++) {
            /// value is greater then pivot swift after the pivot index.
            if (array[index].bit_count < pivot_value) {
                swap(array, ++pivot_index, index);
            } else if (array[index].bit_count == pivot_value && array[index].data < original_pivot_data) {
                swap(array, ++pivot_index, index);
            }
        }
        swap(array, ++pivot_index, end_index);
        quickSort(array, start_index, pivot_index-1);
        quickSort(array, pivot_index+1, end_index);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    int* sorted_numbers_by_bits = (int*)malloc(arrSize*sizeof(int));
    if (sorted_numbers_by_bits != NULL) {
        struct bit_with_data array_ref[500];

        for (int index = 0; index < arrSize; index++) {
            int data = arr[index];
            int bit_count = 0;

            for (int bit_index = 0; bit_index < 32; bit_index++) {
                if ((data & 1) == 1) {
                    bit_count++;
                }
                data >>= 1;
            }
            
            struct bit_with_data data_ref;
            data_ref.data = arr[index];
            data_ref.bit_count = bit_count;

            array_ref[index] = data_ref;
        }

        quickSort(array_ref, 0, arrSize-1);

        for (int index = 0; index < arrSize; index++) {
            sorted_numbers_by_bits[index] = array_ref[index].data;
        }
        *returnSize = arrSize;
    }

    return sorted_numbers_by_bits;
}