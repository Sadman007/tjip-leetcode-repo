#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = strs[0];
        for (string str : strs)
        {
            for (int i = 0; i < result.size(); i++)
            {
                if (str[i] != result[i])
                    result = result.substr(0, i);
            }
        }
        return result;
    }
};