class Solution:
    def singleNumber(self, nums):
        
        if  len(nums) == 1:
            return nums[0]
        result = nums[0]
        for idx in range (1, len(nums)):
            result = result ^ nums[idx]   
        return result

        