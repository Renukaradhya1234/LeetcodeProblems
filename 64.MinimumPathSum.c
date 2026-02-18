int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    /// updated all last row with suffix...
    int grid_row_size = gridSize-1;
    int grid_column_size = gridColSize[grid_row_size]-1;
    int suffix = 0;
    for (int index = grid_column_size; index >= 0; index--) {
        suffix += grid[grid_row_size][index];
        grid[grid_row_size][index] = suffix;
    }

    suffix = 0;
    for (int index = grid_row_size; index >= 0; index--) {
        suffix += grid[index][grid_column_size];
        grid[index][grid_column_size] = suffix;
    }

    for (int grid_row_index = grid_row_size-1; grid_row_index >= 0; grid_row_index--) {
        for (int grid_column_index = grid_column_size-1; grid_column_index >= 0; grid_column_index--) {
            grid[grid_row_index][grid_column_index] += min(grid[grid_row_index][grid_column_index+1], grid[grid_row_index+1][grid_column_index]);
        }
    }

    return grid[0][0];
}