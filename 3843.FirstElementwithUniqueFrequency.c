#include <stdlib.h>

int firstUniqueFreq(int* nums, int numsSize) {
    int* number_frequency;
    int* frequency_group;
    int max_value = 0;

    for (int index = 0; index < numsSize; index++) {
        int current_value = nums[index];
        if (current_value > max_value) {
            max_value = current_value;
        }  
    }

    int result = -1;
    
    number_frequency = (int*)calloc(max_value+1, sizeof(int));
    if (number_frequency == NULL) {
        return result;
    }
    frequency_group = (int*)calloc(numsSize+1, sizeof(int));
    if (frequency_group == NULL) {
        free(number_frequency);
        return result;
    }

    for (int index = 0; index < numsSize; index++) {
        number_frequency[ nums[index] ]++;
    }

    for (int index = 0; index <= max_value; index++) {
        frequency_group[ number_frequency[index] ]++;
    }

    for (int index = 0; index < numsSize; index++) {
        int current_value = nums[index];
        int current_number_frequency = number_frequency[current_value];
        if (frequency_group[current_number_frequency] == 1) {
            result = current_value;
            break;
        }
    }

    free(number_frequency);
    free(frequency_group);
    return result;
}