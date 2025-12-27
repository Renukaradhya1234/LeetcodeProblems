#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int* k_weakest_rows = (int*)malloc(k*sizeof(int));
    if (k_weakest_rows != NULL) {
        int solider_buffer[101] = {0};
        int row_soldier_buffer[100] = {0};

        for (int row_index = 0; row_index < matSize; row_index++) {
            int column_size = matColSize[row_index];
            int solider_count = 0;
            for (int column_index = 0; column_index < column_size; column_index++) {
                if (mat[row_index][column_index] == 0) {
                    break;
                }
                solider_count++;
            }
            row_soldier_buffer[row_index] = solider_count;
            solider_buffer[solider_count]++;
        }

        int prefix_sum = 0;
        for (int index = 0; index < 101; index++) {
            prefix_sum += solider_buffer[index];
            solider_buffer[index] = prefix_sum;
        }

        int sorted_solider_buffer[100] = {0};

        for (int index = matSize-1; index >= 0; index--) {
            int value = row_soldier_buffer[index];
            int update_index = --solider_buffer[value];
            sorted_solider_buffer[update_index] = index;
        }

        for (int index = 0; index < k; index++) {
            k_weakest_rows[index] = sorted_solider_buffer[index];
        }

        *returnSize = k;
    }

    return k_weakest_rows;
}