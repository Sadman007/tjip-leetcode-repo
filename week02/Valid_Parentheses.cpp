class Solution {
public:
    bool isValid(string s) {
      stack<char>check;
        map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';

        for(auto ch:s){

            if(ch=='('|| ch=='{' || ch=='[')
                check.push(ch);
            else{
                if (!check.empty() && check.top()==mp[ch])
                    check.pop();
                else
                    return false;
            }
        }

        return check.empty();
    }

};
