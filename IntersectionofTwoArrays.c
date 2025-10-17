#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int num1_ref[1001] = { 0 };

    for (int index = 0; index < nums1Size; index++) {
        num1_ref[ nums1[index] ] = 1;
    }

    int total_size = 0;
    for (int index = 0; index < nums2Size; index++) {
        if (num1_ref[ nums2[index] ] == 1) {
            total_size++;
            num1_ref[ nums2[index] ]++;
        }
    }

    int* intersection_number = (int*)calloc(total_size, sizeof(int));
    *returnSize = total_size;
    if (intersection_number != NULL && total_size > 0) {
        int index_ref = 0;
        for (int index = 0; index < nums2Size; index++) {
            if (num1_ref[ nums2[index] ] == 2) {
                intersection_number[index_ref++] = nums2[index];
                num1_ref[ nums2[index] ]++;
            }
        }
    }

    return intersection_number;
}
