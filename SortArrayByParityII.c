/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int current_even_index = 0;
    int current_odd_index = 1;

    
    while (current_even_index < numsSize && current_odd_index < numsSize) {
        /// keep moving till we find the even index with value odd...
        while (current_even_index < numsSize && nums[current_even_index] % 2 == 0) {
            current_even_index+=2;
        }

        /// keep moving till we find the odd index with value even...
        while (current_odd_index < numsSize && nums[current_odd_index] % 2 == 1) {
            current_odd_index += 2;
        }

        /// if inner while loop breaks in between with reaching end...
        /// then swap the values...
        if (current_even_index < numsSize && current_odd_index < numsSize) {
            int temp = nums[current_even_index];
            nums[current_even_index] = nums[current_odd_index];
            nums[current_odd_index] = temp;
        }
    }

    *returnSize = numsSize;
    return nums;
}
