# problem link: https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lists = {}
        
        for i in range(len(nums)):
            seen = target - nums[i]
            if seen in lists:
                return [lists[seen], i]
            lists.update({nums[i]: i})
            
        return []