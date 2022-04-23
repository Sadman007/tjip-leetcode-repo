#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int n = s.size();
        int ans = 0;
        unordered_map<string, int> mp;
        for (auto &str : words)
        {
            mp[str]++;
        }
        for (auto &str : mp)
        {
            int k = str.first.size();
            int i = 0;
            for (auto &x : s)
            {
                if (str.first[i] == x)
                    i++;
                if (i == k)
                {
                    ans = ans + str.second;
                    break;
                }
            }
        }
        return ans;
    }
};