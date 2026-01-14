void swap(int** array, int first_index, int second_index) {
    int* temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void setPivotValueToLast(int** array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    int start_index_value = array[start_index][1];
    int mid_index_value = array[mid_index][1];
    int end_index_value = array[end_index][1];
    
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

void insertionSort(int** array, int start_index, int end_index) {
    for (int index = start_index+1; index <= end_index; index++) {
        int* current_value = array[index];
        int index_to_insert = index-1;

        while (index_to_insert >= start_index && (array[index_to_insert][1] < current_value[1] || (array[index_to_insert][1] == current_value[1] && array[index_to_insert][0] > current_value[0]))) {
            array[index_to_insert+1] = array[index_to_insert];
            index_to_insert--;
        }

        array[index_to_insert+1] = current_value;
    }
}

void quickSort(int** array, int start_index, int end_index) {
    if (start_index < end_index) {
        if ((end_index-start_index)+1 <= 64) {
            insertionSort(array, start_index, end_index);
        } else {
            setPivotValueToLast(array, start_index, end_index);
            int pivot_index = start_index-1;
            int* pivot_value = array[end_index];
            int pivot_value_data = pivot_value[1];
    
            for (int index = start_index; index < end_index; index++) {
                if (array[index][1] > pivot_value_data) {
                    swap(array, ++pivot_index, index);
                } else if (array[index][1] == pivot_value_data && array[index][0] < pivot_value[0]) {
                    swap(array, ++pivot_index, index);
                }
            }
            swap(array, ++pivot_index, end_index);
            quickSort(array, start_index, pivot_index-1);
            quickSort(array, pivot_index+1, end_index);
        }
    }
}

void sort(int** box_types, int total_size) {
    if (total_size <= 64) {
        insertionSort(box_types, 0, total_size-1);
    } else {
        quickSort(box_types, 0, total_size-1);
    }
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    sort(boxTypes, boxTypesSize);
    int max_units = 0;
    int used_box_size = 0;
    for (int index = 0; index < boxTypesSize; index++) {
        int* current_value = boxTypes[index];
        int required_boxes = truckSize-used_box_size;
        if (required_boxes > current_value[0]) {
            max_units += current_value[0]*current_value[1];
            used_box_size += current_value[0];
        } else {
            max_units += required_boxes*current_value[1];
            used_box_size += required_boxes;
        }

        if (used_box_size >= truckSize) {
            break;
        }
    }

    return max_units;
}