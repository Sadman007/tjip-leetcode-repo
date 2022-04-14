class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> freq(256, 0);
        int L = 0, R = 0, largest_len = 0, flag = 0;

        while (R < s.size())
        {
            freq[s[R]]++;
            if (freq[s[R]] > 1)
                flag++;
            R++;

            while (flag > 0)
            {
                freq[s[L]]--;
                if (freq[s[L]] == 1)
                    flag--;
                L++;
            }
            largest_len = max(largest_len, R - L);
        }
        return largest_len;
    }
};