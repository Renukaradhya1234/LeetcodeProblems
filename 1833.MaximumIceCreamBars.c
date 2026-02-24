#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool countingSort(int* num_array, int num_array_size, int min_value, int max_value) {
    int total_range = (max_value-min_value)+1;
    int* num_buffer = (int*)calloc(total_range, sizeof(int));
    if (num_buffer == NULL) {
        return false;
    }

    for (int index = 0; index < num_array_size; index++) {
        num_buffer[ num_array[index]-min_value ]++;
    }

    int start_index = 0;
    for (int index = 0; index < total_range; index++) {
        int current_value = index+min_value;
        for (int count = num_buffer[index]; count > 0; count--) {
            num_array[start_index++] = current_value;
        }
    }

    free(num_buffer);
    return true;
}

void heapify(int* num_array, int num_array_size, int current_index) {
    while (true) {
        int largest_index = current_index;
        int left_child_index = (2*current_index)+1;
        int right_child_index = (2*current_index)+2;

        if (left_child_index < num_array_size && num_array[largest_index] < num_array[left_child_index]) {
            largest_index = left_child_index;
        }

        if (right_child_index < num_array_size && num_array[largest_index] < num_array[right_child_index]) {
            largest_index = right_child_index;
        }

        if (largest_index == current_index) {
            break;
        }

        int temp = num_array[largest_index];
        num_array[largest_index] = num_array[current_index];
        num_array[current_index] = temp;
        current_index = largest_index;
    }
}

void heapSort(int* num_array, int num_array_size) {
    for (int index = (num_array_size/2)-1; index >= 0; index--) {
        heapify(num_array, num_array_size, index);
    }

    for (int index = num_array_size-1; index >= 0; index--) {
        int temp = num_array[index];
        num_array[index] = num_array[0];
        num_array[0] = temp;
        heapify(num_array, index, 0);
    }
}

void sort(int* num_array, int num_array_size) {
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    for (int index = 0; index < num_array_size; index++) {
        int current_value = num_array[index];
        max_value = MAX(max_value, current_value);
        min_value = MIN(min_value, current_value);
    }

    int total_range = (max_value-min_value)+1;
    if (total_range <= num_array_size*2) {
        bool sort_status = countingSort(num_array, num_array_size, min_value, max_value);
        if (!sort_status) {
            heapSort(num_array, num_array_size);
        }
    } else {
        heapSort(num_array, num_array_size);
    }
}

int maxIceCream(int* costs, int costsSize, int coins) {
    sort(costs, costsSize);

    int count = 0;

    for (int index = 0; index < costsSize; index++) {
        int current_cost = costs[index];
        if (coins < current_cost) {
            break;
        }
        count++;
        coins -= current_cost;
    }

    return count;
}