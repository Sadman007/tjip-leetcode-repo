class Solution:
    def firstMissingPositive(self, nums):

        size = len(nums)

        for idx in range(0, size):
            if  nums[idx] <= 0 or nums[idx] > size:
                nums[idx] =  size+1

        for idx in range(0,size):
            idx_value = abs(nums[idx]) 
            if  idx_value <=size:
                idx_value -=1
                if nums[idx_value] > 0:
                    nums[idx_value] *= -1

        for i in range(0, size):
            if nums[i]>=0:
                return i + 1

        return size +1
                
        
                
            
                
    
                
            
        
            
