#include <stdbool.h>
#include <stdlib.h>

static long long *tbl;
static unsigned mask;
#define EMPTY 0x7FFFFFFFFFFFLL   // sentinel outside int range

static void insert(long long x) {
    unsigned h = ((unsigned)x * 2654435761u) & mask;
    while (tbl[h] != EMPTY) {
        if (tbl[h] == x) return;
        h = (h + 1) & mask;
    }
    tbl[h] = x;
}

static bool contains(long long x) {
    unsigned h = ((unsigned)x * 2654435761u) & mask;
    while (tbl[h] != EMPTY) {
        if (tbl[h] == x) return true;
        h = (h + 1) & mask;
    }
    return false;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int cap = 1;
    while (cap < numsSize * 2) cap <<= 1;   // load factor <= 0.5
    tbl = malloc(cap * sizeof(long long));
    mask = cap - 1;
    for (int i = 0; i < cap; i++) tbl[i] = EMPTY;
    for (int i = 0; i < numsSize; i++) insert(nums[i]);
    int best = 0;
    for (int i = 0; i < cap; i++) {
        if (tbl[i] == EMPTY) continue;
        long long v = tbl[i];
        if (contains(v - 1)) continue;      // not a sequence start
        int len = 1;
        while (contains(v + len)) len++;
        if (len > best) best = len;
    }
    free(tbl);
    return best;
}
