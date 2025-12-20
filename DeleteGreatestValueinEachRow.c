int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
    int number_buffer[101] = {0};
    int column_size = gridColSize[0];
    for (int index = 0; index < gridSize; index++) {
        int* inner_cell = grid[index];
        for (int inner_index = 0; inner_index < column_size; inner_index++) {
            number_buffer[ inner_cell[inner_index] ]++;
        }

        int start_index = 0;
        for (int number_index = 0; number_index < 101; number_index++) {
            for (int count = number_buffer[number_index]; count > 0; count--) {
                inner_cell[start_index++] = number_index;
            }

            number_buffer[number_index] = 0;
        }
    }

    int greatest_value = 0;
    for (int column_index = 0; column_index < column_size; column_index++ ) {
        int max_value = 0;
        for (int row_index = 0; row_index < gridSize; row_index++) {
            int value = grid[row_index][column_index];
            if (value > max_value) {
                max_value = value;
            }
        }
        greatest_value += max_value;
    }

    return greatest_value;
}