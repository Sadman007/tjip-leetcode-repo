# o(N) time | O(1) space
"""
Description: we are using XOR. In XOR if two numbers are same the result is 0, otherwise 1.
"""

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        
        for num in nums:
            result = num ^ result
        return result