import unittest


class Solution:
    def moveZeroes(self, nums):
        
        left_idx = -1  # last non zero index from left
        
        for idx in range(0, len(nums)):
            if nums[idx] != 0:
                left_idx +=1
                nums[left_idx], nums[idx] = nums[idx], nums[left_idx]


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.Solution = Solution()

        self.test_cases = [
            [[0,1,0,3,4,6], [1,3,4,6,0,0]],
            [[1,5,6,0,0,0,0], [1,5,6,0,0,0,0]],
            [[2,3,4,5,6],[2,3,4,5,6]],
            [[0,0,0,0], [0,0,0,0]]
        ]

    def test_solution(self):
        for nums, expected in self.test_cases:
           
            self.Solution.moveZeroes(nums) # this method changes the argument nums array  in-place 
           
            assert  nums == expected


if __name__ == "__main__":
    unittest.main()

