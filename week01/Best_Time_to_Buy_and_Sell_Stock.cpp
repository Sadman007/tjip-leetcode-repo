class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int R = prices.size() - 1, res = 0, mnL = (int) 1e9;
        for(int i = 0; i < R; i++) {
            mnL = min(mnL, prices[i]);
            res = max(res, prices[i+1] - mnL);
        }
        return res;
    }
};
