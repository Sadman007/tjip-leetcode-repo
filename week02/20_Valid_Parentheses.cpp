//20. Valid Parentheses
//TC: O(N)
//MC: O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; s[i]; i++){
            char ch = s[i];
            if(ch == ')' || ch == '}' || ch == ']'){
                if(!stk.size()) return 0;
                char topChar = stk.top();
                stk.pop();
                if((topChar == '(' && ch != ')') || (topChar == '{' && ch != '}') || (topChar == '[' && ch != ']')) return false;
            }
            else stk.push(ch);
        }
        return (!stk.size());
    }
};
