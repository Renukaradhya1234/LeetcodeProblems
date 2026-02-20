int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return max(nums[0], nums[1]);
    }

    int previous_max = nums[0];
    int second_previous_max = nums[1];
    int max_rob = max(previous_max, second_previous_max);

    for (int index = 2; index < numsSize; index++) {
        int current_max = nums[index] + previous_max;

        previous_max = max(previous_max, second_previous_max);
        second_previous_max = current_max;
        max_rob = max(current_max, max_rob);
    }

    return max_rob;
}