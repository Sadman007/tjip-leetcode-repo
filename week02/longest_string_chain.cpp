// TC: O(N^2)
// MC: O(N)
bool cmp(string &a, string &b)
{
    return a.size() < b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>dp;
        int res = 0;
        for(auto &word : words)
        {
            int best = 0;
            for(int i = 0; i < word.size(); i++)
            {
                string wd = word.substr(0,i) + word.substr(i + 1);
                best = max(best,dp[wd] + 1);
            }
            dp[word] = best;
            res = max(res,best);
        }
        return res;
    }
};