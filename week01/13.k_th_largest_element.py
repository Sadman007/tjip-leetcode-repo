# First approach: O(NlogN) time | O(1) space

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True) 
        return nums[k-1]


#=========================Second Approach=========================
"""
Using quick select algo: O(N) time | O(N) space
Description: 
1.First, we need to choose so-called pivot and partition element of nums into 3 parts: elements, smaller than pivot, equal to pivot and bigger than pivot. (sometimes two groups enough: less and more or equal)
2.Next step is to see how many elements we have in each group: if k <= L, where L is size of left, than we can be sure that we need to look into the left part. If k > L + M, where M is size of mid group, than we can be sure, that we need to look into the right part. Finally, if none of these two condition holds, we need to look in the mid part, but because all elements there are equal, we can immedietly return mid[0].
** Video Link: ** https://www.youtube.com/watch?v=BP7GCALO2v8
"""

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if not nums: return
        
        pivot = random.choice(nums)
        
        leftArr = [x for x in nums if x > pivot]
        midArr = [x for x in nums if x == pivot]
        rightArr = [x for x in nums if x < pivot]
        
        left = len(leftArr)
        right = len(midArr)
        
        if k <= left:
            return self.findKthLargest(leftArr, k)
        elif k > left+right:
            return self.findKthLargest(rightArr, k-left-right)
        else:
            return midArr[0]