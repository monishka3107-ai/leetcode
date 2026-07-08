#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int n = numCourses, m = prerequisitesSize;
    int *indeg = calloc(n, sizeof(int));
    int *head = malloc(n * sizeof(int));
    int *next = malloc((m > 0 ? m : 1) * sizeof(int));
    int *to = malloc((m > 0 ? m : 1) * sizeof(int));
    memset(head, -1, n * sizeof(int));
    for (int i = 0; i < m; i++) {
        int a = prerequisites[i][0], b = prerequisites[i][1]; // edge b -> a
        to[i] = a;
        next[i] = head[b];
        head[b] = i;
        indeg[a]++;
    }
    int *q = malloc(n * sizeof(int));
    int h = 0, t = 0;
    for (int i = 0; i < n; i++)
        if (!indeg[i]) q[t++] = i;
    while (h < t) {
        int u = q[h++];
        for (int e = head[u]; e != -1; e = next[e])
            if (--indeg[to[e]] == 0) q[t++] = to[e];
    }
    bool res = (t == n);
    free(indeg); free(head); free(next); free(to); free(q);
    return res;
}