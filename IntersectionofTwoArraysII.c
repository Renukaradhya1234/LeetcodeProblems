/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    unsigned int intersection_number_ref[1001] = {0};
    for (unsigned int index = 0; index < nums1Size; index++) {
        intersection_number_ref[ nums1[index] ]++;
    }

    unsigned int min_size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* intersection_items = (int*)malloc(min_size*sizeof(int));
    
    unsigned int total_intersection_length = 0;
    for (unsigned int index = 0; index < nums2Size; index++) {
        if (intersection_number_ref[ nums2[index] ] > 0) {
            intersection_items[total_intersection_length++] = nums2[index];
            intersection_number_ref[ nums2[index] ]--;
        }
    }

    *returnSize = total_intersection_length;
    return intersection_items;
}