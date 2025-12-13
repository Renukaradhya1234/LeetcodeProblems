int findMaxK(int* nums, int numsSize) {
    int number_buffer[1001] = { 0 };

    for (int index = 0; index < numsSize; index++) {
        if (nums[index] < 0) {
            number_buffer[ -nums[index] ]++;
        }
    }

    int result = -1;
    for (int index = 0; index < numsSize; index++) {
        if (nums[index] > 0 && number_buffer[ nums[index] ] > 0) {
            if (nums[index] > result) {
                result = nums[index];
            }
        }
    }

    return result;
}