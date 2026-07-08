/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int counts[1001] = {0};
    
    for (int i = 0; i < nums1Size; i++) {
        counts[nums1[i]]++;
    }
    
    int maxResultSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxResultSize * sizeof(int));
    int k = 0;
    
    for (int i = 0; i < nums2Size; i++) {
        if (counts[nums2[i]] > 0) {
            result[k++] = nums2[i];
            counts[nums2[i]]--;
        }
    }
    
    *returnSize = k;
    return result;
}