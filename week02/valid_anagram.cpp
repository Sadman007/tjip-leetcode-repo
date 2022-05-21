// TC: O(N)
// MC: O(1)

class Solution {
public:
    const long long MOD = 202206214218227LL; // use a large sophie germain prime for less collisions! FYI, 10^9 + 7 is a sophie germain prime.
    long long getHash(string &s) {
        long long h = 1;
        for (auto c : s) {
            h = h * (c + 257) % MOD;
        }
        return h;
    }
    bool isAnagram(string s, string t) {
        return getHash(s) == getHash(t);
    }
};