int dominantIndex(int* nums, int numsSize) {
    int largest_number_index = -1;
    int track_largest_number_index = 0;
    int largest_number = nums[0];
    for (int index = 1; index < numsSize; index++) {
        if (nums[index] > largest_number) {
            largest_number = nums[index];
            track_largest_number_index = index;
        }
    }

    int valid = 1;
    for (int index = 0; index < numsSize; index++) {
        if (index != track_largest_number_index) {
            if (nums[index] * 2 > largest_number) {
                valid = 0;
                break;
            }
        }
    }

    if (valid == 1) {
        largest_number_index = track_largest_number_index;
    }
    return largest_number_index;
}