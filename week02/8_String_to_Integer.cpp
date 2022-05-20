//8. String to Integer (atoi)
//TC: O(N)
//MC: O(1)

class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = 0;
        long long val = 0;
        int i = 0;
        while(s[i] == ' ') i++;
        if(s[i] == '-') {
            isNegative = -1;
            i++;
        }
        else if(s[i] == '+') i++;

        for(int j = i; s[j]; j++){
            if(!isdigit(s[j])) break;
            val = val * 10 + s[j] - '0';
            if(!isNegative && val > INT_MAX) val = INT_MAX;
            if(isNegative && val > INT_MAX + 1LL) val = INT_MAX + 1LL;
        }
        if(isNegative) val = -val;

        return (int)val;
    }
};
