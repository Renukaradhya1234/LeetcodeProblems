int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    int positive_num_buffer[101] = {0};
    int negative_num_buffer[101] = {0};

    for (int index = 0; index < numsSize; index++) {
        if (nums[index] >= 0) {
            positive_num_buffer[ nums[index] ]++;
        } else {
            negative_num_buffer[ -nums[index] ]++;
        }
    }
    
    for (int index = 100; index >= 0 && k > 0; index--) {
        for (int count = negative_num_buffer[index]; count > 0 && k > 0; count--) {
            negative_num_buffer[index]--;
            positive_num_buffer[index]++;
            k--;
        }
    }

    if (k % 2 == 1) {
        for (int index = 0; index < 101; index++) {
            if (positive_num_buffer[index] > 0) {
                positive_num_buffer[index]--;
                negative_num_buffer[index]++;
                break;
            }
        }
    }

    int total_sum = 0;
    
    for (int index = 0; index < 101; index++) {
        total_sum += index * positive_num_buffer[index];
        total_sum -= index * negative_num_buffer[index];
    }
    return total_sum;
}