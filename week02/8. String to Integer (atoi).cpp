//Time complexity - 0(n)
//space complexity - 0(1)
class Solution {
public:
    int myAtoi(string s) {

        int i = 0 , sign = 1 , num = 0;

        if(s.length() ==0)return 0;

        while(s[i] == ' '){
            i++;
        }

        if((s[i] == '+' || s[i] == '-' ) && s.length() >1 ){

            sign = (s[i] == '-' ? -1 : 1);
            i++;
        }

        if(s[i] - '0' < 0 || s[i] - '0' > 9){
            return 0;
        }

        while(i<s.length() && s[i] >= '0' && s[i] <= '9'){

            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7))
            {
              if (sign == 1)
                return INT_MAX;
              else
                return INT_MIN;
            }
            num = num*10 + (s[i] - '0');
            i++;
        }



        return num * sign ;


    }
};
