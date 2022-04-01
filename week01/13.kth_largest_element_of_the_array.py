class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        result = self.kth_position(nums, 0, len(nums)-1, k)
        return result    

    def kth_position(self,nums, start, end, k): 
        pivot = self.partition(nums, start, end)
        if pivot+1 == k:
            return nums[pivot]
        elif pivot < k:
            return  self.kth_position(nums,pivot+1, end,k)
        else:
            return  self.kth_position(nums,start,pivot-1,k)
            
    def partition(self, nums,start, end):
        first = start
        pivot = nums[end]
        for  idx in range(start, end):
            if nums[idx] > pivot:
                nums[first], nums[idx]= nums[idx], nums[first]
                first+=1     
        nums[first], nums[end]= nums[end], nums[first]
        return first
                    