static void dfs(char** g, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '1') return;
    g[i][j] = '0';
    dfs(g, m, n, i + 1, j);
    dfs(g, m, n, i - 1, j);
    dfs(g, m, n, i, j + 1);
    dfs(g, m, n, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridColSize[i]; j++)
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize[i], i, j);
            }
    return count;
}
