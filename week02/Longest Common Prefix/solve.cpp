class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        if(str.size() == 1) return str[0];
        string temp = str[0];
        string ans = "";
        for(int i=0; i<temp.length(); i++)
        {
            bool got = true;
            char ch = temp[i];
            for(int j = 0; j<str.size(); j++)
            {
                string tp = str[j];
                if(tp[i]!=ch)
                {
                    got = false;
                }
            }
            if(got)
            {
                ans += ch;
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};
