# O(N) time | O(1) space complexity

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        index = 0
        majorityElement = 0
        majorityElementCount = 0
        
        while index < len(nums):
                
            if majorityElementCount == 0 or majorityElement == nums[index]:
                majorityElement = nums[index]
                majorityElementCount += 1   
                
            elif majorityElement != nums[index]:
                majorityElementCount -= 1 

            index += 1
            
        return majorityElement