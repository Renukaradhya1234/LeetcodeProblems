#include <stdlib.h>

void mergeSort(int* original_array, int start_index, int end_index, int* temp_array) {
    if (start_index < end_index) {
        int mid_index = start_index + (end_index-start_index)/2;
        mergeSort(original_array, start_index, mid_index, temp_array);
        mergeSort(original_array, mid_index+1, end_index, temp_array);
        int temp_start = start_index;
        int temp_mid = mid_index+1;
        int temp_array_index = start_index;
        while (temp_start <= mid_index && temp_mid <= end_index) {
            if (original_array[temp_start] <= original_array[temp_mid]) {
                temp_array[temp_array_index++] = original_array[temp_start++];
            } else {
                temp_array[temp_array_index++] = original_array[temp_mid++];
            }
        }

        while (temp_start <= mid_index) {
            temp_array[temp_array_index++] = original_array[temp_start++];
        }

        while (temp_mid <= end_index) {
            temp_array[temp_array_index++] = original_array[temp_mid++];
        }

        for (int index = start_index; index <= end_index; index++) {
            original_array[index] = temp_array[index];
        }
    }
}

void swap(int* array, int first_index, int second_index) {
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void heapify(int* array, int total_size, int current_index) {
    int largest_num_index = current_index;
    int left_child_index = 2*current_index + 1;
    int right_child_index = 2*current_index + 2;

    if (left_child_index < total_size && array[left_child_index] > array[largest_num_index]) {
        largest_num_index = left_child_index;
    }

    if (right_child_index < total_size && array[right_child_index] > array[largest_num_index]) {
        largest_num_index = right_child_index;
    }

    if (largest_num_index != current_index) {
        swap(array, largest_num_index, current_index);
        heapify(array, total_size, largest_num_index);
    }
}

void heapSort(int* array, int total_size) {
    int non_leaf_node_start_index = total_size/2-1;   
    for (int index = non_leaf_node_start_index; index >= 0; index--) {
        heapify(array, total_size, index);
    }

    for (int index_from_last = total_size-1; index_from_last > 0; index_from_last--) {
        swap(array, 0, index_from_last);
        heapify(array, index_from_last, 0);
    }
}

void insertionSort(int* array,int start_index, int end_index) {
    for (int index = start_index+1; index <= end_index; index++) {
        int current_value = array[index];
        int index_to_insert = index-1;
        while (index_to_insert >= start_index && array[index_to_insert] > current_value) {
            array[index_to_insert+1] = array[index_to_insert];
            index_to_insert--;
        }
        array[index_to_insert+1] = current_value;
    }
}

void sort(int* arr, int arrSize) {
    if (arrSize <= 64) {
        insertionSort(arr, 0, arrSize-1);
    } else {
        int* temp_arr = (int*)malloc(arrSize*sizeof(int));
        if (temp_arr != NULL) {
            mergeSort(arr, 0, arrSize-1, temp_arr);
        } else {
            heapSort(arr, arrSize);
        }
        free(temp_arr);
    }
}

void swapPointer(int** pointer_array, int first_index, int second_index) {
    int* temp = pointer_array[first_index];
    pointer_array[first_index] = pointer_array[second_index];
    pointer_array[second_index] = temp;
}

void heapifyPointer(int** pointer_array, int total_size, int current_index) {
    int largest_index = current_index;
    int left_child_index = 2*current_index+1;
    int right_child_index = 2*current_index+2;

    if (left_child_index < total_size && pointer_array[left_child_index][0] > pointer_array[largest_index][0]) {
        largest_index = left_child_index;
    }

    if (right_child_index < total_size && pointer_array[right_child_index][0] > pointer_array[largest_index][0]) {
        largest_index = right_child_index;
    }

    if (largest_index != current_index) {
        swapPointer(pointer_array, largest_index, current_index);
        heapifyPointer(pointer_array, total_size, largest_index);
    }
}

void heapSortForPointer(int** pointer_array, int pointer_size) {
    int non_leap_node_index = pointer_size/2-1;
    for (int index = non_leap_node_index; index >= 0; index--) {
        heapifyPointer(pointer_array, pointer_size, index);
    }

    for (int index_from_last = pointer_size-1; index_from_last > 0; index_from_last--) {
        swapPointer(pointer_array, index_from_last, 0);
        heapifyPointer(pointer_array, index_from_last, 0);
    }
}

void insertionSortForPointer(int** pointer_array, int pointer_size) {
    for (int index = 0; index < pointer_size; index++) {
        int* current_value = pointer_array[index];
        int index_to_insert = index-1;
        while (index_to_insert >= 0 && pointer_array[index_to_insert][0] > current_value[0]) {
            pointer_array[index_to_insert+1] = pointer_array[index_to_insert];
            index_to_insert--;
        }
        pointer_array[index_to_insert+1] = current_value;
    }
}

void sortPointer(int** pointer_array, int pointer_size) {
    if (pointer_size <= 64) {
        insertionSortForPointer(pointer_array, pointer_size);
    } else {
        heapSortForPointer(pointer_array, pointer_size);
    }
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int max_width = 0;
    int* x_co_ordinates = (int*)malloc(pointsSize*sizeof(int));
    if (x_co_ordinates != NULL) {
        for (int index = 0; index < pointsSize; index++) {
            x_co_ordinates[index] = points[index][0];
        }

        sort(x_co_ordinates, pointsSize);

        for (int index = 1; index < pointsSize; index++) {
            int difference = x_co_ordinates[index]-x_co_ordinates[index-1];
            if (difference > max_width) {
                max_width = difference;
            }
        }
    } else {
        sortPointer(points, pointsSize);

        for (int index = 1; index < pointsSize; index++) {
            int difference = points[index][0] - points[index-1][0];
            if (difference > max_width) {
                max_width = difference;
            }
        }
    }

    free(x_co_ordinates);
    return max_width;
}