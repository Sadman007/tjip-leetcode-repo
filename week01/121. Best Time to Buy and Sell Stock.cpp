// TC: O(N)
// MC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int max_prof = 0;
       int min_price = prices[0];
        
       for(auto nums: prices){
           min_price = min(min_price,nums);
           int profit = nums - min_price;
           max_prof = max(max_prof , profit);
       }

        return max_prof;
    }
};