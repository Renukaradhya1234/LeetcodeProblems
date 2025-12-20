int missingInteger(int* nums, int numsSize) {
    int number_buffer[52] = {0};
    
    int seq_max_number = nums[0];
    int prefix_number = nums[0];
    
    number_buffer[ nums[0] ] = 1;
    
    int index = 1;
    int number;
    while (index < numsSize) {
        number = nums[index];
        if (number != seq_max_number+1) {
            break;
        }
        seq_max_number++;
        prefix_number += number;

        index++;
        number_buffer[ number ] = 1;
    }

    while (index < numsSize) {
        number = nums[index];
        number_buffer[ number ] = 1;      
        index++;
    }
    
    int missing_integer = prefix_number;
    if (prefix_number <= 51) {
        for (int index = prefix_number; index <= 51; index++) {
            if (number_buffer[index] == 0) {
                missing_integer = index;
                break;
            }
        }
    } 

    return missing_integer;
}