import unittest


class Solution:
    def merge(self, nums1, m, nums2, n):
        nums1_pos = m-1
        nums2_pos = n-1
        merged_pos = len(nums1)-1

        while nums1_pos >=0 and nums2_pos >=0:

            if nums1[nums1_pos] > nums2[nums2_pos]:
                nums1[merged_pos] = nums1[nums1_pos]
                nums1_pos -=1
            else:
                nums1[merged_pos] = nums2[nums2_pos]
                nums2_pos -=1
                
            merged_pos -=1
            
        while nums1_pos >=0 :
            nums1[merged_pos] = nums1[nums1_pos]
            nums1_pos -=1
            merged_pos -=1
            
        while nums2_pos >=0:
            nums1[merged_pos]  = nums2[nums2_pos]
            nums2_pos -= 1
            merged_pos -=1


class TestSolution(unittest.TestCase):

    def setUp(self):
        self.Solution = Solution()
        self.test_cases = [
            [[1,2,3,0,0,0],3, [2,5,6],3, [1,2,2,3,5,6]],
            [[1,3,5,0,0], 3, [2,4], 2, [1,2,3,4,5]]
        ]

    def test_solution(self):
            
        for nums1,m, nums2,n, expected in self.test_cases:
            self.Solution.merge(nums1,m,nums2,n) # this method changes the argumet nums1 array  in-place 
            assert nums1 == expected

        
if __name__ == "__main__" :
    unittest.main()

            
            