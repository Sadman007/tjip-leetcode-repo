#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int lb = needle.size();
        int la = haystack.size();
        for (int i = 0; i <= (la - lb); i++)
        {
            if (haystack.substr(i, lb) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};