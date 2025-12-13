/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int number_buffer[101] = { 0 };

    *returnSize = numsSize;

    /// take all even index values...
    for (int index = 0; index < numsSize; index += 2) {
        number_buffer[ nums[index] ]++;
    }

    int start_index = 0;
    for (int index = 0; index < 101; index++) {
        for (int count = number_buffer[index]; count > 0; count--) {
            nums[start_index] = index;
            start_index += 2;
        }
        number_buffer[index] = 0;
    }

    for (int index = 1; index < numsSize; index += 2) {
        number_buffer[ nums[index] ]++;
    }

    start_index = 1;
    for (int index = 100; index > 0; index--) {
        for (int count = number_buffer[index]; count > 0; count--) {
            nums[start_index] = index;
            start_index += 2;
        }
        number_buffer[index] = 0;
    }
    return nums;
}