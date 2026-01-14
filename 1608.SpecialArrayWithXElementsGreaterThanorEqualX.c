int specialArray(int* nums, int numsSize) {
    int special_array = -1;
    
    for (int number = 0; number <= numsSize; number++) {
        int count = 0;
        for (int index = 0; index < numsSize; index++) {
            if (nums[index] >= number) {
                count++;
                if (count > number) {
                    break;
                }
            }
        }
        if (number == count) {
            special_array = number;
            break;
        }
    }

    return special_array;
}