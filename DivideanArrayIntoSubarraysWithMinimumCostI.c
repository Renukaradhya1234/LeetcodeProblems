int minimumCost(int* nums, int numsSize) {
    int first_min_value = nums[0];
    int second_min_value = 51;
    int thrid_min_value = 51;
    
    for (int index = 1; index < numsSize; index++) {
        if (nums[index] < second_min_value) {
            thrid_min_value = second_min_value;
            second_min_value = nums[index];
        } else if (nums[index] < thrid_min_value) {
            thrid_min_value = nums[index];
        }
    }   

    return first_min_value + second_min_value + thrid_min_value;
}