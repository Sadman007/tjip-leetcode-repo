// TC: O(N)
// MC: O(N)

class Solution {
public:
    static const long long MOD = 202206214218227LL;
    long long getHash(string &str) {
        long long h = 1;
        for (auto c : str) {
            h = (h * (257 + (c - 'a'))) % MOD;
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> buckets;
        for (auto &str : strs) {
            buckets[getHash(str)].push_back(str);
        }
        vector<vector<string>> anagrams;
        for (auto &item : buckets) {
            anagrams.push_back(item.second);
        }
        return anagrams;
    }
};