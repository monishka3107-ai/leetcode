#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for result
    int* result = (int*)malloc(2 * sizeof(int));

    // Brute force approach (safe for all constraints)
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;  // IMPORTANT for LeetCode
                return result;
            }
        }
    }

    *returnSize = 2;
    return result;
}