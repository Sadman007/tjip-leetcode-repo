// TC: O(N + M)
// MC: O(N)

class Solution {
public:
    vector<long long> prefixHashHaystack, po;
    long long MOD = 202206214218227LL;
    int base = 29;
    
    void preprocess(string &haystack) {
        prefixHashHaystack[0] = haystack[0];
        for (int i = 1; i < haystack.size(); i++) {
            prefixHashHaystack[i] = ((1LL * prefixHashHaystack[i - 1] * base) + haystack[i]) % MOD;
            po[i] = (po[i - 1] * base) % MOD;
        }
    }
    
    long long getRangeHash(int L, int R) {
        long long x1 = prefixHashHaystack[R];
        long long x2 = L == 0 ? 0 : ((__int128)prefixHashHaystack[L - 1] * po[R - L + 1]) % MOD;
        return (x1 - x2 + MOD) % MOD;
    }
    
    long long generateHash(string &str) {
        long long h = 0;
        for (auto s : str) {
            h = (h * base) + s;
            h %= MOD;
        }
        return h;
    }
    
    int strStr(string haystack, string needle) {
        int lb = needle.size();
        int la = haystack.size();
        prefixHashHaystack.resize(la + 1, 0);
        po.resize(la + 1, 1);
        preprocess(haystack);
        
        long long nH = generateHash(needle);

        for (int i = 0; i <= (la - lb); i++) {
            if (getRangeHash(i, i + lb - 1) == nH) {
                return i;
            }
        }
        return -1;
    }
};

