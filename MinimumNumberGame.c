#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberGame(int* nums, int numsSize, int* returnSize) {
    int* game_result = (int*)malloc(numsSize*sizeof(int));
    if (game_result != NULL) {
        *returnSize = numsSize;
        int num_buffer[101] = {0};
        for (int index = 0; index < numsSize; index++) {
            num_buffer[ nums[index] ]++;
        }

        int start_index = 0;
        for (int index = 0; index < 101; index++) {
            for (int count = num_buffer[index]; count > 0; count--) {
                game_result[start_index] = index;
                start_index++;
            }
        }

        for (int index = 0; index < numsSize; index+=2) {
            int temp = game_result[index];
            game_result[index] = game_result[index+1];
            game_result[index+1] = temp;
        }
    }

    return game_result;
}