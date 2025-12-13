int findFinalValue(int* nums, int numsSize, int original) {
    int buffer_value[1001] = {0};

    for (int index = 0; index < numsSize; index++) {
        buffer_value[ nums[index] ] = 1;
    }

    while (original <= 1000) {
        if (buffer_value[original] == 0) {
            break;
        }

        original *= 2;
    }
    return original;
}

