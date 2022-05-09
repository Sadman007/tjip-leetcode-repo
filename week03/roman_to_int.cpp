class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> flag = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int res = flag[s[s.size()-1]];
        for(int i=s.size()-2; i>=0; i--) {
            if(flag[s[i]] < flag[s[i+1]]) res -= flag[s[i]];
            else res += flag[s[i]];
        }
        return res;
    }
};
