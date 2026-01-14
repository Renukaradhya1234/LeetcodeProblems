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
            if (array[index] < pivot_value) {
                swap(array, ++pivot_index, index);
            }
        }
        swap(array, ++pivot_index, end_index);
        quickSort(array, start_index, pivot_index-1);
        quickSort(array, pivot_index+1, end_index);
    }
}

int getNearestValue(int* array, int start_index, int end_index, int target) {
    int left = start_index;
    int right = end_index;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Now:
    // left  -> first index >= target
    // right -> last index < target

    // If target is smaller than all elements
    if (right < start_index) {
        return array[left];
    }

    // If target is larger than all elements
    if (left > end_index) {
        return array[right];
    }

    // Compare both neighbors
    if (abs(array[left] - target) < abs(array[right] - target)) {
        return array[left];
    } else {
        return array[right];
    }
}


int abs(int number) {
    if (number < 0) {
        number = -number;
    }
    return number;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    quickSort(arr2, 0, arr2Size-1);

    int result = 0;

    for (int index = 0; index < arr1Size; index++) {
        int nearest_value = getNearestValue(arr2, 0, arr2Size-1, arr1[index]);
        if (abs(arr1[index] - nearest_value) > d) {
            result++;
        }
    }

    return result;
}