int countElements(int* nums, int numsSize) {
    int count_element = 0;
    int max_value = -1000000;
    int min_value = 1000000;

    for (int index = 0; index < numsSize; index++) {
        if (nums[index] < min_value) {
            min_value = nums[index];
        }

        if (nums[index] > max_value) {
            max_value = nums[index];
        }
    }

    if (max_value != min_value) {
        int max_value_count = 0;
        int min_value_count = 0;

        for (int index = 0; index < numsSize; index++) {
            if (nums[index] == max_value) {
                max_value_count++;
            } else if (nums[index] == min_value) {
                min_value_count++;
            }
        }

        count_element = numsSize - (min_value_count + max_value_count);
    }

    return count_element;
}

