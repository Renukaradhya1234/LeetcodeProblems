#include <stdbool.h>
#include <stdlib.h>

struct indexMapper {
    int index;
    int value;
};

void swapTheValues(struct indexMapper* index_mapper, int start_index, int end_index) {
    struct indexMapper index_mapper_temp = index_mapper[start_index];
    index_mapper[start_index] = index_mapper[end_index];
    index_mapper[end_index] = index_mapper_temp;
}

void setPivotValueToLast(struct indexMapper* index_mapper, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    /// finding the hightest value index....
    if (index_mapper[start_index].value > index_mapper[mid_index].value && index_mapper[start_index].value > index_mapper[end_index].value) {
        highest_index = start_index;
    } else if (index_mapper[mid_index].value > index_mapper[start_index].value && index_mapper[mid_index].value > index_mapper[end_index].value) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }

    if (start_index == highest_index) {
        if (index_mapper[mid_index].value > index_mapper[end_index].value) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (index_mapper[start_index].value > index_mapper[end_index].value) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (index_mapper[start_index].value > index_mapper[mid_index].value) {
            mean_index = start_index;
        } else {
            mean_index = mid_index;
        }
    }

    if (end_index != mean_index) {
        swapTheValues(index_mapper, mean_index, end_index);
    }
}

int absolute(int first_value, int second_value) {
    int result = first_value - second_value;
    if (result < 0) {
        result = -result;
    }
    return result;
}

bool containsNearbyDuplicateHelper(struct indexMapper* index_mapper, int start_index, int end_index, int absolute_value) {
    bool duplicate_present = false;
    if (start_index < end_index) {
        setPivotValueToLast(index_mapper, start_index, end_index);
        struct indexMapper pivot_value = index_mapper[end_index];
        int pivot_index = start_index - 1;

        for (int index = start_index; index < end_index; index++) {
            if (index_mapper[index].value < pivot_value.value) {
                swapTheValues(index_mapper, ++pivot_index, index);
            } else if (index_mapper[index].value == pivot_value.value) {
                int absolute_val_ref = absolute(index_mapper[index].index, pivot_value.index);
                if (absolute_val_ref <= absolute_value) {
                    duplicate_present = true;
                    break;
                }
            }
        }
        if (!duplicate_present) {
            /// swap the pivot value...
            swapTheValues(index_mapper, ++pivot_index, end_index);
            duplicate_present = containsNearbyDuplicateHelper(index_mapper, start_index, pivot_index-1, absolute_value);
            if (!duplicate_present) {
                duplicate_present = containsNearbyDuplicateHelper(index_mapper, pivot_index+1, end_index, absolute_value);
            }
        }
    }
    return duplicate_present;
}


bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct indexMapper* index_mapper = (struct indexMapper*)malloc(numsSize*sizeof(struct indexMapper));
    bool result = false;
    if (index_mapper != NULL) {
        for (int index = 0; index < numsSize; index++) {
            index_mapper[index].index = index;
            index_mapper[index].value = nums[index];
        }
        result = containsNearbyDuplicateHelper(index_mapper, 0, numsSize-1, k);
        free(index_mapper);
    } else {
        for (int index = 0; index < numsSize; index++) {
            int total_iteration = index+k;
            for (int sub_index = index+1; sub_index < numsSize && sub_index <= total_iteration; sub_index++) {
                if (nums[index] == nums[sub_index]) {
                    result = true;
                    break;
                }
            }
            if (result) {
                break;
            }
        }
    }

    return result;
}