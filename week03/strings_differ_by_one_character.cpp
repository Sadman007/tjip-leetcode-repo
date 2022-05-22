/**
Time: O(N), where N = total number of strings
Memory: O(N)
**/

class Solution {
public:
    const static long long MOD = 202206214218227LL;
    
    long long getHash(string &str) {
        long long h = 0;
        for (auto &c : str) {
            h = (h * 257) + c;
            if (h >= MOD) h %= MOD;
        }
        return h;
    }
    
    bool differByOne(vector<string>& dict) {
        unordered_set<long long> hashedStrings;
        int L = dict[0].size();
        for (auto &curr : dict) {
            long long h = getHash(curr);
            long long mult = 1;
            for (int i = L - 1; i >= 0; i--) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (curr[i] == c) continue;
                    int diff = c - curr[i];
                    long long newHash = h + (1LL * diff * mult % MOD) + MOD;
                    if (newHash >= MOD) newHash %= MOD;
                    if (hashedStrings.count(newHash)) {
                        return true;
                    }
                }
                mult = (mult * 257) % MOD;
            }
            hashedStrings.insert(h);
        }
        return false;    
    }
};