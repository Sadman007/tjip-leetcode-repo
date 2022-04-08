# O(N) time | O(1) space complexity

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyDay = 0
        sellDay = 1
        profit = 0
        i=0
        
        while i < len(prices):
            if sellDay < len(prices) and prices[buyDay] < prices[sellDay]:
                profit += prices[sellDay]-prices[buyDay]
            i += 1
            buyDay,sellDay= i,i+1
        return profit


# Optimal in code:
# O(N) time | O(1) space complexity
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = total = 0
        right = 1
        while(right < len(prices)):
            if prices[right] > prices[left]:
                total += prices[right] - prices[left]
            left = right
            right += 1
        return total