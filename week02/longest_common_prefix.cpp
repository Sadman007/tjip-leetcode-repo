class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        sort(begin(strs), end(strs));
        string a = strs[0], b = strs[strs.size()-1];
        for(int i=0; i<a.size(); i++) {
            if(a[i] == b[i])
                res += a[i];
            else
                break;
        }
        return res;
    }
};
