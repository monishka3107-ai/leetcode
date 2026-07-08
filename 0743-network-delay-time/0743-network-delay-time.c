#include <stdbool.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    static int g[101][101];
    int dist[101];
    bool vis[101];
    const int INF = INT_MAX / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) g[i][j] = INF;
        dist[i] = INF;
        vis[i] = false;
    }
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        if (w < g[u][v]) g[u][v] = w;
    }
    dist[k] = 0;
    for (int it = 0; it < n; it++) {
        int u = -1, best = INF;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dist[i] < best) { best = dist[i]; u = i; }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 1; v <= n; v++)
            if (dist[u] + g[u][v] < dist[v]) dist[v] = dist[u] + g[u][v];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > ans) ans = dist[i];
    }
    return ans;
}