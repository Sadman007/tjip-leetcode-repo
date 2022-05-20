//394. Decode String
//TC: O(|S|*|result|) -> result := output_string
//MC: O(|result|)

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        int R = 0;
        while(s[R]){
            if(s[R] == ']'){
                string cur = "";
                while(stk.top() != '['){
                    cur = stk.top() + cur;
                    stk.pop();
                }
                stk.pop();

                string num = "";
                while(stk.size() && isdigit(stk.top())){
                    num = stk.top() + num;
                    stk.pop();
                }
                int times = stoi(num);

                string res = "";
                for(int i = 0; i < times; i++) res += cur;
                for(char ch : res) stk.push(ch);
            }
            else stk.push(s[R]);
            R++;

        }
        string result = "";
        while(stk.size()){
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};
