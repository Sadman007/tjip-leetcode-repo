class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());

        string start=strs[0];
        string end= strs[strs.size()-1];

        string ans="";

        int len=max(start.size(),end.size());

        for(int i=0;i<len;i++){

            if(start[i]==end[i])
                ans+=start[i];
            else
                break;
        }
        return ans;

    }
};
