#include <stdlib.h>
#include <string.h>

#define OFFSET 50000
#define RANGE 100001   // -5*10^4 .. 5*10^4

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int *count = calloc(RANGE, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        count[nums[i] + OFFSET]++;
    int *res = malloc(numsSize * sizeof(int));
    int k = 0;
    for (int v = 0; v < RANGE; v++)
        while (count[v]--)
            res[k++] = v - OFFSET;
    free(count);
    *returnSize = numsSize;
    return res;
}