#O(N) time | O(1) space
"""
find next permutation: 
1. find peak value
2. replace last value with peak's previous value
3. sort after replaced the values
"""

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        for i in range(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                j = i
                while j < n and nums[j] > nums[i-1]:
                    idx = j
                    j += 1
                nums[i-1], nums[idx] = nums[idx], nums[i-1]
                for k in range((n-i)//2):
                    nums[i+k],nums[n-1-k] = nums[n-1-k],nums[i+k]
                break
        else:
            nums.reverse()
        