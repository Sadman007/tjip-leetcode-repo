// O(N)
// O(1)
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1, idx = 0;

        while(idx < s.size() && s[idx]==' ') idx++;

        if(idx < s.size() && s[idx]=='+'){
            idx++; sign = 1;
        }
        else if(idx < s.size() && s[idx]=='-'){
            idx++; sign = -1;
        }

        for(;idx<s.size();idx++){
            if(!isdigit(s[idx])) break;
            if(ans>INT_MAX) break;

            ans = (ans*10) + s[idx]-'0';
        }
        ans = sign * ans;
        ans = max(ans, 1LL*INT_MIN);// min(),max() er param same data type er howa lagbe
        ans = min(ans, 1LL*INT_MAX);
        return ans;
    }
};
