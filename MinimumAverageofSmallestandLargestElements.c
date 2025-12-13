double minimumAverage(int* nums, int numsSize) {
    int num_buffer[51] = {0};

    for (int index = 0; index < numsSize; index++) {
        num_buffer[ nums[index] ]++;
    }

    int start_index = 0;
    int end_index = 50;

    double average = 50.0;

    while (start_index <= end_index) {
        while (start_index <= end_index && num_buffer[start_index] == 0) {
            start_index++;
        }

        while (end_index >= start_index && num_buffer[end_index] == 0) {
            end_index--;
        }

        if (start_index > end_index) {
            break;
        }

        num_buffer[start_index]--;
        num_buffer[end_index]--;

        double temp_average = (start_index+end_index)/2.0;
        if (temp_average < average) {
            average = temp_average;
        }
    }

    return average;
}