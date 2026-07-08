#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int *q = malloc(m * n * sizeof(int));
    int head = 0, tail = 0, fresh = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q[tail++] = i * n + j;
            else if (grid[i][j] == 1) fresh++;
        }
    int minutes = 0;
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (head < tail && fresh > 0) {
        int size = tail - head;
        minutes++;
        for (int s = 0; s < size; s++) {
            int cur = q[head++], r = cur / n, c = cur % n;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q[tail++] = nr * n + nc;
                }
            }
        }
    }
    free(q);
    return fresh ? -1 : minutes;
}
