class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int mx_profit = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            buy = min(buy, prices[i]);

            int profit = prices[i] - buy;

            mx_profit = max(profit, mx_profit);
        }
        return mx_profit;

    }
};
