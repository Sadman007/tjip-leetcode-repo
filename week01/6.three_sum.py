#O(N^2) time | O(N) space

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        for i,a in enumerate(nums):
            if i > 0 and nums[i-1] == a:
                continue
                
            l,r = i+1, len(nums)-1
            
            while l < r:
                threeSum = a+nums[l]+nums[r]
                if threeSum > 0: 
                    r -= 1
                elif threeSum < 0: 
                    l += 1
                else:
                    result.append([nums[i],nums[l],nums[r]])
                    l += 1
                    while nums[l] == nums[l-1] and l<r:
                        l += 1
                    
        return result

#second approach: using hashmap:
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        seen = set()
        target = 0
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                val = target - nums[i] -nums[j]
                if val in seen:
                    arr = sorted([val, nums[i], nums[j]])
                    result.add((arr[0], arr[1], arr[2]))
            seen.add(nums[i])
        return result