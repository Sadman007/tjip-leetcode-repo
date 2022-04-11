class Solution {
public:
    int myAtoi(string s) {
        bool minus = false;
        int i=0;
        int len = s.length();
        long long ans = 0;
        while(i<len and s[i] == ' ') i++;
        if(i<len and s[i] == '-') minus = true; 
        if(i<len and (s[i] == '-' or s[i] == '+')) i++;
        bool overflow = false;
        while(i<len)
        {
            long long value = s[i]-'0';
            if(value < 0 or value >9) break;
            else
            {
                ans = ans*10 + value;;
                if(ans > 2147483647)
                {
                    overflow = true;
                    break;
                }
            }
            i++;
        }
        if(overflow)
        {
            if(minus) return INT_MIN;
            else return INT_MAX;
        }
        return minus == true?ans*(-1):ans;
    }
};
