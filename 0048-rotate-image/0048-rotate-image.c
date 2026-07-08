void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    // transpose
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    // reverse each row
    for (int i = 0; i < n; i++)
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            int t = matrix[i][l];
            matrix[i][l] = matrix[i][r];
            matrix[i][r] = t;
        }
}