class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i;
        int mi=prices[0];
        int maxprof=0;
        for(i=0;i<prices.size();i++){
            mi=min(mi,prices[i]);
            maxprof=max(maxprof,prices[i]-mi);
            
        }
        return maxprof;
          
            
        
    }
};