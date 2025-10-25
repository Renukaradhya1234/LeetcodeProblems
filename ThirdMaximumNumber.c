int thirdMax(int* nums, int numsSize) {
    int first_max_index = -1;
    int second_max_index = -1;
    int third_max_index = -1;

    for (int index = 0; index < numsSize; index++) {
        if (first_max_index == -1) {
            first_max_index = index;
        } else {
            int current_number = nums[index];
            if (current_number == nums[first_max_index]) {
                continue;
            }
            
            if (current_number > nums[first_max_index]) {
                third_max_index = second_max_index;
                second_max_index = first_max_index;
                first_max_index = index;
            } else {
                if (second_max_index == -1) {
                    second_max_index = index;
                } else {
                    if (current_number == nums[second_max_index]) {
                        continue;
                    }

                    if (current_number > nums[second_max_index]) {
                        third_max_index = second_max_index;
                        second_max_index = index;
                    } else {
                        if (third_max_index == -1 || current_number > nums[third_max_index]) {
                            third_max_index = index;
                        } 
                    }
                }
            }
        }
    }

    int result = nums[first_max_index];
    if (third_max_index != -1) {
        result = nums[third_max_index];
    }
    return result;
}