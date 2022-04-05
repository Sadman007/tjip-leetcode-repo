# O(N) time | O(1) space

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longestConsec = 0
        nums = set(nums)
        
        for num in nums:
            if num-1 not in nums:
                curr = num
                while(curr in nums):
                    curr += 1
                longestConsec = max(longestConsec, curr-num)
        return longestConsec