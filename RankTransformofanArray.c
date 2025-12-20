#include <stdlib.h>

struct RankValue {
    int data;
    int index;
    int rank;
};


void swap(struct RankValue* array, int first_index, int second_index) {
    struct RankValue temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}


void setPivotValueToLast(struct RankValue* array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    int start_index_data = array[start_index].data;
    int mid_index_data = array[mid_index].data;
    int end_index_data = array[end_index].data;
    
    /// finding the hightest value index....
    if (start_index_data > mid_index_data && start_index_data > end_index_data) {
        highest_index = start_index;
    } else if (mid_index_data > start_index_data && mid_index_data > end_index_data) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }
    
    
    if (start_index == highest_index) {
        if (mid_index_data > end_index_data) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (start_index_data > end_index_data) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (start_index_data > mid_index_data) {
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

void sort(struct RankValue* array, int start_index, int end_index) {
    if (start_index < end_index) {
        setPivotValueToLast(array, start_index, end_index);
        int pivot_index = start_index-1;
        int pivot_value = array[end_index].data;

        for (int index = start_index; index < end_index; index++) {
            /// value is greater then pivot swift after the pivot index.
            if (array[index].data < pivot_value) {
                swap(array, ++pivot_index, index);
            }
        }

        swap(array, ++pivot_index, end_index);
        sort(array, start_index, pivot_index-1);
        sort(array, pivot_index+1, end_index);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    struct RankValue* array_rank_transform = (struct RankValue*)malloc(arrSize*sizeof(struct RankValue));
    int* array_rank = (int*)malloc(arrSize*sizeof(int));
    if (arrSize > 0 && array_rank_transform != NULL && array_rank != NULL) {
        for (int index = 0; index < arrSize; index++) {
            struct RankValue rank_value;
            rank_value.index = index;
            rank_value.data = arr[index];
            rank_value.rank = 0;
            array_rank_transform[index] = rank_value;
        }

        sort(array_rank_transform, 0, arrSize-1);

        int prev_value = array_rank_transform[0].data;
        int rank = 1;
        for (int index = 0; index < arrSize; index++) {
            struct RankValue rank_value = array_rank_transform[index];
            if (rank_value.data != prev_value) {
                rank_value.rank = ++rank;
            } else {
                rank_value.rank = rank;
            }
            prev_value = rank_value.data;
            array_rank[rank_value.index] = rank_value.rank;
        }
    } 
    free(array_rank_transform);
    *returnSize = arrSize;
    return array_rank;
}