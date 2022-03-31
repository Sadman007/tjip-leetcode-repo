class Solution:
    def maxProfit(self, prices):
        
        local_minimum = prices[0]
        total_profit = 0
        
        for idx in range(1, len(prices)):
             if prices[idx] < prices[idx-1]:
                total_profit += prices[idx-1] - local_minimum
                local_minimum = prices[idx]
                    
        if local_minimum < prices[len(prices)-1]:
            total_profit += prices[len(prices)-1] - local_minimum
            
            
        return total_profit