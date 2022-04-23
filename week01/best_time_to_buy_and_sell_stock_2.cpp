// TC: O(N)
// MC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mx = 0;
        for(int i = 0; i + 1 < p.size(); i++)
            if(p[i + 1] > p[i])
                mx += p[i + 1] - p[i];
        return mx;
    }
};