//14. Longest Common Prefix
//TC: O(N*|S|)
//MC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size(), len = 0;
        if(sz == 1) return strs[0];
        strs[sz-1].push_back('#');
        bool flag = 1;
        while(flag){
            for(int i = 1; i < sz; i++){
                if(strs[0][len] != strs[i][len]) flag = 0;
            }
            len++;
        }

        return strs[0].substr(0, len-1);
    }
};
