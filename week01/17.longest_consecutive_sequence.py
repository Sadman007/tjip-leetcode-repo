class Solution:
    def longestConsecutive(self, nums):
        
        nums_set  = set(nums)
        max_sequence = 0
        for idx in range (0, len(nums)):
            if nums[idx] -1  not in nums_set:
                current_sequence = 1
                current_num = nums[idx]+1
                while current_num in nums_set:
                    current_sequence +=1
                    current_num+=1
                    
                max_sequence = current_sequence if current_sequence > max_sequence else max_sequence
                
        return max_sequence 