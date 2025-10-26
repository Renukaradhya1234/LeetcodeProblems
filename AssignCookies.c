#include <stdlib.h>

void binaryInsertionSort(int* num_array, int start_index, int end_index) {
    // best algorithm for small array...
    for (int index = start_index; index <= end_index; index++) {
        int current_value = num_array[index];

        int bin_start_index = start_index;
        int bin_end_index = index-1;

        while (bin_start_index <= bin_end_index) {
            int mid_index = bin_start_index + ( (bin_end_index-bin_start_index)/2 );
            if (num_array[mid_index] > current_value) {
                bin_end_index = mid_index-1;
            } else {
                bin_start_index = mid_index+1;
            }
        }

        for (int shift_index = index-1; shift_index >= bin_start_index; shift_index++) {
            num_array[shift_index+1] = num_array[shift_index];
        }
        num_array[bin_start_index] = current_value;
    }
}

void mergeSort(int* num_array, int* temp_array, int start_index, int end_index) {
    if (start_index < end_index) {
        int mid_index = start_index + (end_index - start_index) / 2;
        mergeSort(num_array, temp_array, start_index, mid_index);
        mergeSort(num_array, temp_array, mid_index+1, end_index);

        int left_index = start_index;
        int right_index = mid_index+1;
        int temp_index = start_index;

        while (left_index <= mid_index && right_index <= end_index) {
            if (num_array[left_index] < num_array[right_index]) {
                temp_array[temp_index++] = num_array[left_index++];
            } else {
                temp_array[temp_index++] = num_array[right_index++];
            }
        }

        while (left_index <= mid_index) {
            temp_array[temp_index++] = num_array[left_index++];
        }

        while (right_index <= end_index) {
            temp_array[temp_index++] = num_array[right_index++];
        }

        for (int index = start_index; index <= end_index; index++) {
            num_array[index] = temp_array[index];
        }
    }
}

void sort(int* num_array, int array_size) {
    int* temp_array = (int*)malloc(array_size*sizeof(int));
    if (temp_array == NULL) {
        binaryInsertionSort(num_array, 0, array_size-1);
    } else {
        mergeSort(num_array, temp_array, 0, array_size-1);
    }
    free(temp_array);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    sort(g, gSize);
    sort(s, sSize);

    int child_index = 0;
    int result = 0;
    for (int index = 0; index < sSize && child_index < gSize; index++) {
        if (s[index] >= g[child_index]) {
            result++;
            child_index++;
        }
    }

    return result;
}



