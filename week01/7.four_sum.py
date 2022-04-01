#O(N^3) time | O(N) space

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = set()
        seen = set()
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    val = target - nums[i] -nums[j] - nums[k]
                    if val in seen:
                        arr = sorted([val, nums[i], nums[j], nums[k]])
                        result.add((arr[0], arr[1], arr[2], arr[3]))
            seen.add(nums[i])
        return result