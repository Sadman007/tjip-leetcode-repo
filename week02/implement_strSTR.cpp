class Solution
{
public:
    vector<long long> prefixHashHaystack, power;
    int base = 29;
    int MOD = 1000000007;

    void preprocess(string &haystack)
    {
        prefixHashHaystack[0] = haystack[0];
        power[0] = 1;
        for (int i = 1; i < haystack.size(); i++)
        {
            prefixHashHaystack[i] = (prefixHashHaystack[i - 1] * base) % MOD;
            prefixHashHaystack[i] += haystack[i];
            power[i] = (power[i - 1] * base) % MOD;
        }
    }

    long long getHash(string &str)
    {
        long long h = 0;
        for (auto s : str)
        {
            h = (h * base) + s;
            h %= MOD;
        }
        return h;
    }

    long long getRangeHash(int L, int R)
    {
        long long right = prefixHashHaystack[R];
        long long left = (L == 0) ? 0 : (prefixHashHaystack[L - 1] * power[R - L + 1]) % MOD;
        return (right - left + MOD) % MOD;
    }

    int strStr(string haystack, string needle)
    {
        int la = haystack.size();
        int lb = needle.size();
        prefixHashHaystack.resize(la + 1, 0);
        power.resize(la + 1, 1);
        preprocess(haystack);
        long long needleHash = getHash(needle);

        for (int i = 0; i <= la - lb; i++)
        {
            if (getRangeHash(i, i + lb - 1) == needleHash)
                return i;
        }
        return -1;
    }
};