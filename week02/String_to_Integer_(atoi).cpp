class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        long long res = 0, mx = 2147483648, mn = -2147483648;
        bool psign = false, nsign = false, num = false;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '+' && !num) psign = true;
            if (s[i] == '-' && !num) nsign = true;
            if (s[i] >= '0' && s[i] <= '9') 
            {
                num = true;
                res = (res * 10) + (s[i] - '0');
                if (res >= mx && !nsign) return mx - 1;
                if (-1*res < mn) return -1*mn;
            }
            if ( (s[i] == '.') || !(s[i] >= '0' && s[i] <= '9') && num) break;
            if ( (psign && nsign) || (s[i] == '+' || s[i] == '-') 
                && !(s[i+1] >= '0' && s[i+1] <= '9')) return 0;
            if (!num && (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ) 
                break;
        }
        if (nsign) return -1*res;
        else return res;
    }
};
