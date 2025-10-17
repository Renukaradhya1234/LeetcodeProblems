int missingNumber(int* nums, int numsSize) {
    int total_sum = 0;

    for (int index = 0; index < numsSize; index++) {
        total_sum += nums[index];
    }

    int expected_sum = (numsSize*(numsSize+1))/2;
    return expected_sum - total_sum;
}