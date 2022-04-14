class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (!stk.empty() && s[i] == ')' && stk.top() == '(')
                stk.pop();
            else if (!stk.empty() && s[i] == '}' && stk.top() == '{')
                stk.pop();
            else if (!stk.empty() && s[i] == ']' && stk.top() == '[')
                stk.pop();
            else
                stk.push(s[i]);
        }
        return stk.empty();
    }
};