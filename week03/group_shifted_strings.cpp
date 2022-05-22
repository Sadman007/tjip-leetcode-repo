/**
Time: O(S), where S = sum of lengths of all strings.
Memory: O(S)
**/
class Solution {
public:
    const static long long MOD = 202206214218227LL;
    long long calculateHash(string &s) {
        long long hash = 0;
        for (auto c : s) {
            hash = (hash * 257) + ((c - s[0] + 26) % 26) + 1;
            if (hash >= MOD) hash %= MOD;
        }
        return hash;
    }
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<long, vector<string>>hashedStrs;
        for(auto &str : strings){
            hashedStrs[calculateHash(str)].push_back(str);
        }
        vector<vector<string>>strGroups;
        for (auto &it : hashedStrs) {
            strGroups.push_back(it.second);
        }
        return strGroups;
    }
};