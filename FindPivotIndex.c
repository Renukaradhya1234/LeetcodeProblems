int pivotIndex(int* nums, int numsSize) {
    int total_sum = 0;
    for (int index = 0; index < numsSize; index++) {
        total_sum += nums[index];
    }   

    int cumulative_sum = 0;
    int pivot_index = -1;
    for (int index = 0; index < numsSize; index++) {
        if (cumulative_sum == total_sum-cumulative_sum-nums[index]) {
            pivot_index = index;
            break;
        }
        cumulative_sum += nums[index];
    }
    return pivot_index;
}