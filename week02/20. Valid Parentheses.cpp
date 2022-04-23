//Time complexity - 0(n)
//space complexity - 0(n)
class Solution {
public:
    bool isValid(string s) {
     stack<char> stk;

     if(s.length() %2 != 0) return false;

     for(int i = 0 ; i < s.length() ; i++){
         if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                stk.push(s[i]);
            }
         else
         {
              if (stk.empty()) return false;

              char ch = stk.top();
              if ((s[i] == '}' && ch == '{') ||(s[i] == ']' && ch == '[') ||
                  (s[i] == ')' && ch == '(')) {
                    stk.pop();
                } else {
                    return false;
                }

         }
     }

     return stk.empty();
    }
};
