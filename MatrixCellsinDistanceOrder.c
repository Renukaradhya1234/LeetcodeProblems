#include <stdlib.h>

int abs(int number) {
    if (number < 0) {
        number = -number;
    }
    return number;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int total_blocks = rows*cols;
    int* count_buffer = (int*)calloc(total_blocks, sizeof(int));
    int** sorted_coordinates = (int**)malloc(total_blocks*sizeof(int*));
    int* column_sizes = (int*)malloc(total_blocks*sizeof(int));

    if (count_buffer != NULL && sorted_coordinates != NULL && column_sizes != NULL) {
        for (int row_index = 0; row_index < rows; row_index++) {
            for (int column_index = 0; column_index < cols; column_index++) {
                int distance = abs(row_index - rCenter) + abs(column_index - cCenter);
                count_buffer[distance]++;
            }
        }
    
        int prefix_sum = 0;
        for (int index = 0; index < total_blocks; index++) {
            prefix_sum += count_buffer[index];
            count_buffer[index] = prefix_sum;
        }

        int allocation_fails = 0;
        for (int row_index = rows-1; row_index >= 0; row_index--) {
            for (int column_index = cols-1; column_index >= 0; column_index--) {
                int distance = abs(row_index - rCenter) + abs(column_index - cCenter);
                int index = --count_buffer[distance];
                int* array = (int*)malloc(2*sizeof(int));
                if (array != NULL) {
                    array[0] = row_index;
                    array[1] = column_index;
                    sorted_coordinates[index] = array;
                    column_sizes[index] = 2;
                } else {
                    allocation_fails = 1;
                    break;
                }
            }
            if (allocation_fails == 1) {
                break;
            }
        }

        if (allocation_fails == 0) {
            *returnSize = total_blocks;
            *returnColumnSizes = column_sizes;
        } 
    } else {
        free(sorted_coordinates);
        sorted_coordinates = NULL;
        free(column_sizes);
        column_sizes = NULL;
    }

    free(count_buffer);

    return sorted_coordinates;
}