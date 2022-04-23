class Solution {
public:
    
    
    bool isOpen(char ch)
    {
        if(ch == '(' or ch == '{' or ch == '[')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
       
        
    bool isValid(string s) {
        
        /// string length = 6;
        map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        stack<char>myStack;
        
        for(char c:s)
        {
            if(isOpen(c))
            {
                myStack.push(mp[c]);
            }
            else
            {
                if(myStack.empty())
                {
                    return false;
                }
                else if(myStack.top() != c)
                {
                    return false;
                }
                else
                {
                    myStack.pop();
                }
            }
        }
        
        return myStack.empty()? true:false;
    }
};
