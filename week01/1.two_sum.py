import unittest

class Solution:
    def twoSum(self, nums, target):
        
        seen = {}
        
        for idx in range (0, len(nums)):
            remainder = target - nums[idx]
            if  remainder in seen :
                    return [seen[remainder], idx]
            
            seen[nums[idx]] = idx
            
        return 0
    

class TestSolution(unittest.TestCase):

    def setUp(self):
        self.Solution = Solution()

        self.test_cases = [
            [[2,7,11,15], 9, [0,1]],
            [[1,9,8, 20],28, [2,3]],
            [[10, 5, 8,7], 14, 0 ]
        ]

    def test_solution(self):
        for nums, target, expected in self.test_cases:
            assert self.Solution.twoSum(nums, target) == expected


if __name__ == "__main__":
    unittest.main()








