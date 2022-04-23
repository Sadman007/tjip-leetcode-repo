#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stck;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stck.push(c);
            }
            else
            {
                if (c == ')' && !stck.empty() && stck.top() == '(')
                    stck.pop();
                else if (c == '}' && !stck.empty() && stck.top() == '{')
                    stck.pop();
                else if (c == ']' && !stck.empty() && stck.top() == '[')
                    stck.pop();
                else
                    return false;
            }
        }
        return stck.empty();
    }
};