class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int startPrice = 0;
        int maxProfit = 0;
        startPrice = prices[0];
        
        for(int i=1; i<prices.size(); i++)
        {   
            if(startPrice>prices[i])
            {
                startPrice = prices[i];
            }
            maxProfit = max(maxProfit,(prices[i]-startPrice));
        }
        return maxProfit;  
    }
};
