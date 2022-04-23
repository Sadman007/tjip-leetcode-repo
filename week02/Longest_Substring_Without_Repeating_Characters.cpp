#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 1)
            return 1;
        int size = 0;
        int i, j;
        for (i = 0; i < s.length(); i++)
        {
            set<int> strSet;
            for (j = i; j < s.length(); j++)
            {
                if (strSet.find(s[j]) != strSet.end())
                {
                    size = max(size, j - i);
                    break;
                }

                else
                    strSet.insert(s[j]);
            }
            size = max(size, j - i);
        }
        return size;
    }
};