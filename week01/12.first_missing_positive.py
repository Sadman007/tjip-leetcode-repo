# #O(N) time | O(1) space
"""
Description: we need to find from 1 to len(nums)+2. As the condition is return missing positive integers, so the range should be total array_items + 1
"""

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = set(nums)
        for i in range(1, len(nums)+2):
            if i not in nums:
                return i
        return 0