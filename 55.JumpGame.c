#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int max_index_can_jump = 0;
    for (int index = 0; index < numsSize; index++) {
        if (index > max_index_can_jump) {
            break;
        }
        int max_jump_length = nums[index];
        if (max_jump_length+index > max_index_can_jump) {
            max_index_can_jump = max_jump_length+index;
        }
    }   

    bool can_jump = false;
    if (max_index_can_jump >= numsSize-1) {
        can_jump = true;
    }
    return can_jump;
}