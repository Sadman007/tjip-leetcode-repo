// TC = O(N)
// MC = O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char,char> closeToOpen{{')','('},{'}','{'},{']','['}};
        for(auto &c:s){
            if(c=='(' or c=='{' or c=='[') open.push(c);
            else{
                if(open.empty()) return false;
                else if(open.top()==closeToOpen[c]) open.pop();
                else return false;
            }
        }
        return open.empty();
    }
};
/**********************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(auto &c:s){
            if(c=='(' || c=='{' || c=='['){
                parentheses.push(c);
            }
            else if(c==')' || c=='}' || c==']'){
                if(parentheses.empty()) return false;
                else{
                    if(c==')' && parentheses.top()=='(') parentheses.pop();
                    else if(c=='}' && parentheses.top()=='{') parentheses.pop();
                    else if(c==']' && parentheses.top()=='[') parentheses.pop();
                    else return false;
                }
            }
        }
        return parentheses.empty();
    }
};
/**********************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(auto &c:s){
            if(c=='(' || c=='{' || c=='['){
                parentheses.push(c);
            }
            else if(c==')' && !parentheses.empty() && parentheses.top()=='('){
                parentheses.pop();
            }
            else if(c=='}' && !parentheses.empty() && parentheses.top()=='{'){
                parentheses.pop();
            }
            else if(c==']' && !parentheses.empty() && parentheses.top()=='['){
                parentheses.pop();
            }
            else return false;
        }
        return parentheses.empty();
    }
};
