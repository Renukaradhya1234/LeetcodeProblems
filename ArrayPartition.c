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

void quickSort(int* array, int start_index, int end_index) {
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
        quickSort(array, start_index, pivot_index-1);
        quickSort(array, pivot_index+1, end_index);
    }
}

int arrayPairSum(int* nums, int numsSize) {
    int result = 0;
    int total_elements = numsSize-1;
    quickSort(nums, 0, total_elements);
    for (int index = 0; index < total_elements; index+=2) {
        result += nums[index];
    }
    return result;
}