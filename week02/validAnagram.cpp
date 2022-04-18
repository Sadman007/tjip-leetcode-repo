class Solution
{
public:
    int MOD = 1000000007;
    int offset = 233;

    long long getHash(string &str)
    {
        long long hashValue = 1;
        for (int i = 0; i < str.size(); i++)
        {
            hashValue = hashValue * (str[i] - 'a' + offset) % MOD;
        }
        return hashValue;
    }

    bool isAnagram(string s, string t)
    {
        return (getHash(s) == getHash(t));
    }
};