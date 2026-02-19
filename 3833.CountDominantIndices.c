int dominantIndices(int* nums, int numsSize) {
    int suffix_sum = nums[--numsSize];
    int number_of_elements = 1;
    
    int count = 0;
    for (int index = numsSize-1; index >= 0; index--) {
        int correct_data = nums[index];
        if (correct_data > (suffix_sum/number_of_elements)) {
            count++;
        }
        number_of_elements++;
        suffix_sum += correct_data;
    }

    return count;
}