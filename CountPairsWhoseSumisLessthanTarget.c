int countPairs(int* nums, int numsSize, int target) {
    int count_pairs = 0;
    int outer_iteration = numsSize-1;
    for (int index = 0; index < outer_iteration; index++) {
        int value = nums[index];
        for (int inner_index = index+1; inner_index < numsSize; inner_index++) {
            if (value + nums[inner_index] < target) {
                count_pairs++;
            }
        }
    }

    return count_pairs;
}