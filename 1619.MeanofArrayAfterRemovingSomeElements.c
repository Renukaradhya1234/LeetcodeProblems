#include <stdlib.h>

// void timSort(int* original_array, int start_index, int end_index, int* temp_array) {

// }

void mergeSort(int* original_array, int start_index, int end_index, int* temp_array) {
    if (start_index < end_index) {
        int mid_index = start_index + (end_index-start_index)/2;
        mergeSort(original_array, start_index, mid_index, temp_array);
        mergeSort(original_array, mid_index+1, end_index, temp_array);
        int temp_start = start_index;
        int temp_end = end_index;
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

    for (int index_from_last = total_size-1; index_from_last >= 0; index_from_last--) {
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

double trimMean(int* arr, int arrSize) {
    sort(arr, arrSize);
    int total_sum = 0;
    int five_per_value = 0.05 * arrSize;
    int end_index = arrSize-five_per_value;
    for (int index = five_per_value; index < end_index; index++) {
        total_sum += arr[index];
    }

    double average = (double)total_sum/(arrSize-five_per_value-five_per_value);
    return average;
}