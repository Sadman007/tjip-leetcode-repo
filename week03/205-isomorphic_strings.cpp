// TC - O(n) n = s.size()
// MC - O(n)
class Solution
{
public:
    int cnt = -1;
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] && mp[s[i]] != t[i])
            {
                return false;
            }
            mp[s[i]] = t[i];
        }
        cnt++;
        if (cnt == 0)
            return isIsomorphic(t, s);
        return true;
    }
};

// TC -
// MC - O(n)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = t[i];
            int count = count_if(mp.begin(), mp.end(),
                                 [&ch](pair<const char, char> &entry)
                                 {
                                     return (entry.second == ch);
                                 });
            if (mp[s[i]] || count)
            {
                str += mp[s[i]];
            }
            else
            {
                mp[s[i]] = t[i];
                str += mp[s[i]];
            }
        }
        return str == t ? true : false;
    }
};