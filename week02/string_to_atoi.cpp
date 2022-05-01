// TC: O(N)
// MC: O(1)
class Solution {
public:
    int myAtoi(string str) {
        long long desired_int = 0;
        int index = 0, sign = 1;
        while(index < str.size() && str[index] == ' ') index++;
        if(index < str.size() && str[index] == '-') {
            sign *= -1;
            index++;
        }
        else if(index < str.size() && str[index] == '+') {
            index++;
        }
        for( ; index < str.size(); index++) {
            if(!isdigit(str[index])) break;
            if(desired_int > INT_MAX || desired_int < INT_MIN) break;
            desired_int = (desired_int * 10) + (str[index] - '0');
        }
        desired_int *= sign;
        desired_int = min(desired_int, 1LL*INT_MAX);
        desired_int = max(desired_int, 1LL*INT_MIN);
        return desired_int;
    }
};