class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.push_back(-1);
        int mxProfit = 0;
        int profitSum = 0 ;
        int startPrice = prices[0];
        int lastPrice = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<lastPrice)
            {
                mxProfit = max(0,lastPrice-startPrice);
                startPrice = prices[i];
                lastPrice = prices[i];
                profitSum += mxProfit;
            } 
            else
            {
                lastPrice = prices[i];
            }
        }
        return profitSum;
    }
};
