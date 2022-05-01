// TC: O(N)
// MC: O(N)

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int> > stk;
        stk.push({"", 0});
        int times = 0;
        for (auto ch : s) {
            if (isdigit(ch)) {
                times = (times * 10) + (ch - '0');
            }
            else if (ch == '[') {
                stk.push({"", times});
                times = 0;
            }
            else if (ch == ']') {
                int cnt = stk.top().second;
                string str = stk.top().first;
                stk.pop();
                while (cnt--) {
                    stk.top().first += str;
                }
            }
            else {
                stk.top().first.push_back(ch);
            }
        }
        return stk.top().first;
    }
};