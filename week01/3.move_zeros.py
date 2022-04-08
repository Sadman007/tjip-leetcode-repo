# problem link: https://leetcode.com/problems/move-zeroes/
# 0(N) time | 0(N) space

# solution-1
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



#solution-2
# 0(N) time | 0(1) space
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numZero = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i],nums[numZero] = nums[numZero],nums[i]
                numZero += 1