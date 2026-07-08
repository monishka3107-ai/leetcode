int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    static int d[100][100];
    const int INF = 1 << 29;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = (i == j) ? 0 : INF;
    for (int e = 0; e < edgesSize; e++) {
        int u = edges[e][0], v = edges[e][1], w = edges[e][2];
        if (w < d[u][v]) { d[u][v] = w; d[v][u] = w; }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
        }
    int best = -1, bestCnt = n + 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i != j && d[i][j] <= distanceThreshold) cnt++;
        if (cnt <= bestCnt) { bestCnt = cnt; best = i; } // tie -> larger index
    }
    return best;
}