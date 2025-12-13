int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int total_apples = 0;
    for (int index = 0; index < appleSize; index++) {
        total_apples += apple[index];
    }

    int boxes_buffer[51] = { 0 };
    for (int index = 0; index < capacitySize; index++) {
        boxes_buffer[ capacity[index] ]++;
    }
    
    int total_boxes_size = 0;
    int required_boxes = 0;
    for (int index = 50; index > 0; index--) {
        int box_frequency = boxes_buffer[index];
        int box_found = 0;
        for (int frequency = box_frequency; frequency > 0; frequency--) {
            total_boxes_size += index;
            required_boxes++;
            if (total_apples <= total_boxes_size) {
                box_found = 1;
                break;
            }
        }

        if (box_found == 1) {
            break;
        }
    }
    return required_boxes;
}