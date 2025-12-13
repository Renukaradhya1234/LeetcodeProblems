/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int frequency_holder[201] = {0};
    for (int index = 0; index < numsSize; index++) {
        frequency_holder[ nums[index] + 100 ]++;
    }

    for (int index = 0; index < numsSize; index++) {
        int value = nums[index];
        int frequency = frequency_holder[value+100];

        int current_index = index-1;

        while (current_index >= 0) {
            int current_value = nums[current_index];
            int current_frequency = frequency_holder[current_value+100];

            if (frequency < current_frequency) {
                nums[current_index+1] = nums[current_index];
            } else if (frequency == current_frequency && value > current_value) {
                nums[current_index+1] = nums[current_index];
            } else {
                break;
            }

            current_index--;
        }

        nums[current_index+1] = value;
    }
    *returnSize = numsSize;
    return nums;
}