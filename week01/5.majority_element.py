
import unittest
class Solution:
    def majorityElement(self, nums):
        
        max_number = 0
        freq_count = 0
        
        for idx in range(0, len(nums)):
            if freq_count == 0:
                max_number = nums[idx]
                freq_count+=1
            else:
                if nums[idx] == max_number:
                    freq_count +=1
                else:
                    freq_count -=1
                    
        return max_number 

class TestSolution(unittest.TestCase):
    
    def setUp(self):
        self.Solution = Solution()
        self.test_cases = [
           [[2,1,2,3,2,5,2,2,7],2],
           [[1,2,3,3,3],3],
           [[1,2,2,1,2],2]
        ]


    def test_solution(self):
        for nums, expected in self.test_cases:
            assert  self.Solution.majorityElement(nums) == expected

if __name__ == "__main__":
    unittest.main()