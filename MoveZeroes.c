void moveZeroes(int* nums, int numsSize) {
    int index = 0;
    
    for (int iterator_index = 0; iterator_index < numsSize; iterator_index++) {
        if (nums[iterator_index] != 0) {
            nums[index] = nums[iterator_index];
            index++;
        }
    }

    while (index < numsSize) {
        nums[index] = 0;
        index++;
    }
}