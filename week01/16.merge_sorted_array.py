# O(N) time | O(1) space
"""
Description: First we create a pointer of last index of nums1 which contains 0. we check if the nums1[m-1] is less than or equal to nums2[n-1], if so then replace nums1 0 with nums2 last val.If not then replace nums1 greater value with nums1 less value. Finally if there is any value in nums2, replace them in nums1
"""

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        lastIdx = m + n -1
        
        while m > 0 and n > 0:
            if nums1[m-1] > nums2[n-1]:
                nums1[lastIdx] = nums1[m-1]
                m -= 1
            else:
                nums1[lastIdx] = nums2[n-1]
                n -= 1
            lastIdx -= 1
        
        while n > 0:
            nums1[lastIdx] = nums2[n-1]
            n -= 1
            lastIdx -= 1
                