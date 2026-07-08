class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lo, hi = min(strs), max(strs)
        for i, ch in enumerate(lo):
            if ch != hi[i]:
                return lo[:i]
        return lo