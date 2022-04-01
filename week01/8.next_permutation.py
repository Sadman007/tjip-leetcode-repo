#O(N) time | O(1) space

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
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
        