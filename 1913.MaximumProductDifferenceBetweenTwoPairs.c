#include <limits.h>

int maxProductDifference(int* nums, int numsSize){
    int first_max = 0;
    int first_min = INT_MAX;
    int second_max = 0;
    int second_min = INT_MAX;

    for (int index = 0; index < numsSize; index++) {
        if (nums[index] > first_max) {
            second_max = first_max;
            first_max = nums[index];
        } else if (nums[index] > second_max) {
            second_max = nums[index];
        }

        if (nums[index] < first_min) {
            second_min = first_min;
            first_min = nums[index];
        } else if (nums[index] < second_min) {
            second_min = nums[index];
        }
    }


    return first_max*second_max - first_min*second_min;
}