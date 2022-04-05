# O(N) time | O(1) space complexity
"""
Description: first we need to multiply with prefix for 0 to N and then again multiply with postfix from (N-1) to 0
"""

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        
        prefix = postfix = 1
        
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix 
            postfix *= nums[i]
        
        return res