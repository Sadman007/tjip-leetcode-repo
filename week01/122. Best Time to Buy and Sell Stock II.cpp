// T - O(n), M - O(1) --> Valley peak approach(https://youtu.be/K8iHi8AW1ls)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                totalProfit += prices[i]-prices[i-1];
            }
        }
        return totalProfit;
    }
};
