class Solution:
    def productExceptSelf(self, nums):
        
        ar_len = len(nums)
        result_arr   = [0]* ar_len
        
        temp_prod = 1
        for i in range(0,ar_len):
            result_arr[i] =  temp_prod
            temp_prod*= nums[i]
            
        temp_prod = 1

        for i in range(ar_len-1, -1, -1):
            result_arr[i] *=  temp_prod
            temp_prod *= nums[i]  
        return result_arr
            