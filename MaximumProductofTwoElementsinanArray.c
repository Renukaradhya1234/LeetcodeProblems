int maxProduct(int* nums, int numsSize) {
    int largest_number = 0;
    int second_largest_number = 0;
    int largest_number_count = 0;
    for (int index = 0; index < numsSize; index++) {
        if (nums[index] == largest_number) {
            largest_number_count++;
        } else if (nums[index] > largest_number) {
            second_largest_number = largest_number;
            largest_number = nums[index];
            largest_number_count = 1;
        } else if (nums[index] > second_largest_number) {
            second_largest_number = nums[index];
        }
    }
    int result = 0;
    if (largest_number_count > 1) {
        result = (largest_number-1) * (largest_number-1);
    } else {
        result = (largest_number-1) * (second_largest_number-1);
    }

    return result;
}