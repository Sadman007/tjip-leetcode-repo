# problem link: https://leetcode.com/problems/move-zeroes/
# 0(N) time | 0(N) space

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        while i < len(nums):
            if nums[i] == 0:
                nums.remove(nums[i])
                nums.append(0)
            i+=1