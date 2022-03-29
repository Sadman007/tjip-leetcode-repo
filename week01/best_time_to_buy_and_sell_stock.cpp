class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0, minPrice = prices[0];
        for(auto price:prices) {
            maxPrice = max(maxPrice, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxPrice;
    }
};
