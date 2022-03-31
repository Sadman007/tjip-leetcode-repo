import unittest

class Solution:
    def maxProfit(self, prices ) :
        
        min_till_now = [None]*len(prices)
        max_from_now = [None] *len(prices)
        
        min_value = float('inf')
        for idx in range (0, len(prices)):  #  calculting  minimum value form start to   current index  
            if prices[idx] < min_value:
                min_value = prices[idx]
            min_till_now[idx] = prices[idx]
                    
        max_value = float("-inf")
        for idx in range(len(prices)-1,-1, -1): #  calculating  maximum value from end to current position
            if prices[idx] > max_value:
                max_value = prices[idx]
            max_from_now[idx] = max_value
                        
        max_profit = 0
        for idx in range(0, len(prices)):
            profit =  max_from_now[idx] - min_till_now[idx]
            if profit > max_profit :
                max_profit = profit
                      
        return max_profit


    def maxProfit_2(self, prices):
        
        min_value = prices[0]
        max_profit = 0
            
        for idx in range(1, len(prices)):
            if prices[idx]<=min_value:
                min_value = prices[idx]      
            else:
                max_profit = max(prices[idx]-min_value, max_profit)        
        return max_profit
    
            
class TestSolution(unittest.TestCase):

    def setUp(self):
        self.Solution = Solution()   
        self.test_cases = [
            [[7,1,5,3,6,4],5],
            [[7,6,4,3,1],0]
        ]  

    def test_solution(self):
        for prices, expected in self.test_cases:
            assert Solution().maxProfit_2(prices) == expected


if __name__ == "__main__":
    unittest.main()        
        
        