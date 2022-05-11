// TC - O(n)
// MC - O(1)
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]])
            {
                res -= mp[s[i]];
            }
            else
            {
                res += mp[s[i]];
            }
        }
        return res;
    }
};

// TC - O(n)
// MC - O(n)
class Solution
{
public:
    int romanToInt(string s)
    {
        int chk[s.size()];
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                chk[i] = 1;
            }
            else if (s[i] == 'V')
            {
                chk[i] = 5;
            }
            else if (s[i] == 'X')
            {
                chk[i] = 10;
            }
            else if (s[i] == 'L')
            {
                chk[i] = 50;
            }
            else if (s[i] == 'C')
            {
                chk[i] = 100;
            }
            else if (s[i] == 'D')
            {
                chk[i] = 500;
            }
            else if (s[i] == 'M')
            {
                chk[i] = 1000;
            }
        }
        int res = 0, flg = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (chk[i] < chk[i + 1])
            {
                res += chk[i + 1] - chk[i];
                if (i + 1 == s.size() - 1)
                {
                    flg++;
                }
                i++;
            }
            else
            {
                res += chk[i];
            }
        }
        if (flg == 0)
        {
            res += chk[s.size() - 1];
        }
        return res;
    }
};