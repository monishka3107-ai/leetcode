
/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/#include <stdlib.h>

#define MAXN 10001   // at most 10^4 pings per constraints

typedef struct {
    int q[MAXN];
    int head, tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter *rc = malloc(sizeof(RecentCounter));
    rc->head = rc->tail = 0;
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->q[obj->tail++] = t;
    while (obj->q[obj->head] < t - 3000) obj->head++;
    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}