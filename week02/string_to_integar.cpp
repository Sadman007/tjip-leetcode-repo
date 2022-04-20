// TC: O(n), MC: O(1)
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        long long res = 0;

        while (i < s.size() and s[i] == ' ')
            i++;

        if (i < s.size() and s[i] == '-')
        {
            i++;
            sign = -1;
        }
        else if (i < s.size() and s[i] == '+')
            i++;

        while (i < s.size() and s[i] >= '0' and s[i] <= '9')
        {
            res = res * 10;
            if (res <= INT_MIN or res >= INT_MAX)
                break;
            res = res + (s[i] - '0');
            i++;
        }

        res *= sign;
        if (res <= INT_MIN)
            return INT_MIN;
        if (res >= INT_MAX)
            return INT_MAX;

        return res;
    }
};