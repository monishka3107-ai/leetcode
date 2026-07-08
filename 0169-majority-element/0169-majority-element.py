class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count, candidate = 0, None
        for x in nums:
            if count == 0:
                candidate = x
            count += 1 if x == candidate else -1
        return candidate