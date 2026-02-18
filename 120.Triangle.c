int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row_index = triangleSize-2; row_index >= 0; row_index--) {
        int row_size = triangleColSize[row_index];
        for (int column_index = 0; column_index < row_size; column_index++) {
            triangle[row_index][column_index] += min(triangle[row_index+1][column_index], triangle[row_index+1][column_index+1]);
        }
    }

    return triangle[0][0];
}