int findKthLargest(int* nums, int numsSize, int k) {
    int count[20001] = {0};   // values -10^4 .. 10^4
    for (int i = 0; i < numsSize; i++)
        count[nums[i] + 10000]++;
    for (int v = 20000; v >= 0; v--) {
        k -= count[v];
        if (k <= 0) return v - 10000;
    }
    return -1; // unreachable
}