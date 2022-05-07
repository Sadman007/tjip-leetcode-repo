class Solution {
public:
    bool isValid(string s) {
        int pos = 0, lim = s.size()/2;
        if(s.size()%2) return false;
        char store[lim];

        for(char c:s) {
            if(c == '(' || c == '{' || c == '[') {
                if(pos == lim) return false;
                store[pos] = c;
                pos = pos + 1;
            }
            else if(pos && abs(store[pos-1] - c) < 3)
                pos--;
            else
                return false;
        }

        return !pos;
    }
};
