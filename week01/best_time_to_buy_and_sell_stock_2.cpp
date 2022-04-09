class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = 0, sell = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] > prices[buy])
                sell = i;
            if(sell > buy)
                profit += prices[sell] - prices[buy];
            buy = sell;
            if(prices[i] < prices[sell])
                buy = i;
        }
        return profit;
    }
};
