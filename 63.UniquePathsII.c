int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int row_size = obstacleGridSize-1;
    int column_size = obstacleGridColSize[0]-1;
    
    /// convert all 1 to -1...
    for (int row_index = 0; row_index <= row_size; row_index++) {
        for (int column_index = 0; column_index <= column_size; column_index++) {
            if (obstacleGrid[row_index][column_index] == 1) {
                obstacleGrid[row_index][column_index] = -1;
            }
        }
    }

    // update the number of paths for last row...
    for (int column_index = column_size; column_index >= 0; column_index--) {
        if (obstacleGrid[row_size][column_index] == -1) {
            break;
        }
        obstacleGrid[row_size][column_index] = 1;
    }

    // update the number of paths for last column...
    for (int row_index = row_size; row_index >= 0; row_index--) {
        if (obstacleGrid[row_index][column_size] == -1) {
            break;
        }
        obstacleGrid[row_index][column_size] = 1;
    }

    /// update the number of paths for remaining cells...
    for (int row_index = row_size-1; row_index >= 0; row_index--) {
        for (int column_index = column_size-1; column_index >= 0; column_index--) {
            if (obstacleGrid[row_index][column_index] == -1) {
                continue;
            }

            unsigned int no_of_paths = 0;
            if (obstacleGrid[row_index][column_index+1] != -1) {
                no_of_paths += obstacleGrid[row_index][column_index+1];
            }

            if (obstacleGrid[row_index+1][column_index] != -1) {
                no_of_paths += obstacleGrid[row_index+1][column_index];
            }

            obstacleGrid[row_index][column_index] = no_of_paths;
        }
    }

    if (obstacleGrid[0][0] != -1) {
        return obstacleGrid[0][0];
    }
    return 0;
}