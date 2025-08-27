#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = 0;
    int candidate_count = 0;

    for (int index = 0; index < numsSize; index++) {
        if (candidate_count == 0) {
            candidate = nums[index];
        }
        candidate_count += (candidate == nums[index]) ? 1 : -1;
    }

    return candidate;
}


int main() {
    int nums[] = { 3,2,3 };
    int total_length = sizeof(nums) / sizeof(int);

    int number = majorityElement(nums, total_length);
    printf("%d\n", number);
    return 0;
}