int maximumProduct(int* nums, int numsSize) {
    int first_max = -1001;
    int second_max = -1001;
    int third_max = -1001;

    int first_min = 1001;
    int second_min = 1001;

    for (int index = 0; index < numsSize; index++) {
        int value = nums[index];
        if (value > first_max) {
            third_max = second_max;
            second_max = first_max;
            first_max = value;
        } else if (value > second_max) {
            third_max = second_max;
            second_max = value;
        } else if (value > third_max) {
            third_max = value;
        }

       if (value < first_min) {
            second_min = first_min;
            first_min = value;
       } else if (value < second_min) {
            second_min = value;
       }
    }

    int max_product = first_max * second_max * third_max;
    int negative_product = first_min * second_min * first_max;
    if (negative_product > max_product) {
        max_product = negative_product;
    }

    return max_product;
}