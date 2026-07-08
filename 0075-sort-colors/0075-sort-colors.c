void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            int t = nums[low]; nums[low] = nums[mid]; nums[mid] = t;
            low++; mid++;
        } else if (nums[mid] == 2) {
            int t = nums[high]; nums[high] = nums[mid]; nums[mid] = t;
            high--;
        } else {
            mid++;
        }
    }
}