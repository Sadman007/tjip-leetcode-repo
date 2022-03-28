# problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyDay = 0
        sellDay = 1
        maximumProfit = 0
        while sellDay < len(prices):
            if prices[sellDay] > prices[buyDay]:
                curProfit = prices[sellDay]-prices[buyDay]
                maximumProfit = max(curProfit, maximumProfit)
            else:
                buyDay = sellDay
            sellDay += 1
        return maximumProfit