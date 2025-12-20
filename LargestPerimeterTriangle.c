void swap(int* array, int first_index, int second_index) {
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

int largestPerimeter(int* nums, int numsSize) {
    int result = 0;
    quickSort(nums, 0, numsSize-1);
    int total_iteration = numsSize-2;
    for (int index = 0; index < total_iteration; index++) {
        if (nums[index] < nums[index+1] + nums[index+2]) {
            result = nums[index] + nums[index+1] + nums[index+2];
            break;
        }
    }   
    return result;
}