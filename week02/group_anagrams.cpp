class Solution
{
public:
    int MOD = 1000000007;
    int offset = 257;
    unsigned long long getHash(string &str)
    {
        unsigned long long hashValue = 1;
        for (int i = 0; i < str.size(); i++)
        {
            hashValue *= (str[i] - 'a' + offset) % MOD;
        }
        return hashValue;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<unsigned long long, vector<string>> bucket;
        vector<vector<string>> anagrams;

        for (auto &str : strs)
        {
            bucket[getHash(str)].push_back(str);
        }
        for (auto &item : bucket)
        {
            anagrams.push_back(item.second);
        }
        return anagrams;
    }
};