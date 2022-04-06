class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        
        first_lower_idx = -1
        
        for idx in range(len(nums)-2, -1,-1):
            if nums[idx] < nums[idx+1]:
                first_lower_idx = idx
                break
                
        if first_lower_idx == -1:
            self.reverse_arr(nums, 0, len(nums)-1)
            return
        
        for idx in range(len(nums)-1,first_lower_idx, -1):
            if nums[idx]> nums[first_lower_idx]:
                nums[first_lower_idx], nums [idx] = nums[idx], nums[first_lower_idx]
                break
                
        self.reverse_arr(nums,first_lower_idx+1, len(nums)-1)
        
    def reverse_arr(self, nums,start, end):
        while start <=end:
            nums[start], nums[end] = nums[end], nums[start]
            start +=1
            end -=1
            
        