/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool flag[1001] = {false};

    for (int i = 0; i < nums1Size; i++) {
        flag[nums1[i]] = true;
    }

    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int index = 0;

    for (int i = 0; i < nums2Size; i++) {
        if (flag[nums2[i]]) {
            result[index++] = nums2[i];
            flag[nums2[i]] = false;
        }
    }

    *returnSize = index;
    return result;
}