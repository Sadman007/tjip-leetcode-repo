//1048. Longest String Chain (iterative approach)
//TC: O(N * |S| * |S|)
//MC: O(N * |S| * |S|)

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res = 1;
        vector<pair<int, string>> vec;
        unordered_map<string, int> dp;
        for(string word : words){
            vec.push_back({-word.size(), word});
            dp[word] = 1;
        }
        sort(vec.begin(), vec.end());

        for(auto it : vec){
            string word = it.second;
            for(int i = 0; word[i]; i++){
                string cur = "";
                for(int j = 0; word[j]; j++){
                    if(i == j) continue;
                    cur += word[j];
                }
                if(dp.count(cur)){
                    dp[cur] =  dp[word] + 1;
                    res = max(res, dp[cur]);
                }
            }
        }

        return res;
    }
};
