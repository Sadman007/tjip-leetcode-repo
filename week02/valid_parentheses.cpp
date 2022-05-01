// TC: O(N)
// MC: O(1)

class Solution {
public:
    bool isValid(string s) {
      stack <char> open;
      unordered_map<char, char> close_to_open;
      close_to_open['}'] = '{';
      close_to_open[')'] = '(';
      close_to_open[']'] = '[';
      for (auto ch : s) {
        if (ch == '(' or ch == '{' or ch == '[') {
            open.push(ch);
        }
        else {
            if (open.empty()) return false;
            else if (open.top() == close_to_open[ch]) open.pop();
            else return false;
        }
      }
      return open.empty();
    }
};