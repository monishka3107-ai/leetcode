#include <stdbool.h>
#include <stdlib.h>

bool containsDuplicate(int* nums, int numsSize) {
    int cap = 1;
    while (cap < numsSize * 2) cap <<= 1;   // power of 2, load factor <= 0.5
    long long *table = malloc(cap * sizeof(long long));
    const long long EMPTY = 0x7FFFFFFFFFFFLL; // outside int range
    for (int i = 0; i < cap; i++) table[i] = EMPTY;
    int mask = cap - 1;
    for (int i = 0; i < numsSize; i++) {
        unsigned int h = ((unsigned int)nums[i] * 2654435761u) & mask;
        while (table[h] != EMPTY) {
            if (table[h] == nums[i]) { free(table); return true; }
            h = (h + 1) & mask;   // linear probing
        }
        table[h] = nums[i];
    }
    free(table);
    return false;
}