/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int even_number_count = 0;
    *returnSize = numsSize;
    for (int index = 0; index < numsSize; index++) {
        if (nums[index] % 2 == 0) {
            even_number_count++;
        }
    }

    int index = 0;
    /// fill all even number...
    while (index < even_number_count) {
        nums[index] = 0;
        index++;
    }

    while (index < numsSize) {
        nums[index] = 1;
        index++;
    }

    return nums;
}