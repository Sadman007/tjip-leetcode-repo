
Problem Link: https://leetcode.com/problems/longest-common-prefix/

TC: (m*n) :- m=min length of strings; n=total strings;
MC: m

string longestCommonPrefix(vector<string>& strs) {
    string commonPrefix="";
    
    for(int j=0 ; j<strs[0].size() ; j++){
        bool containsAllStrings=true;
        
        for(int k=1 ; k<strs.size() ; k++){
            if(strs[k].size()>j && strs[k][j]==strs[0][j]) continue;
            else{
                return commonPrefix;
            }
        }

        commonPrefix.push_back(strs[0][j]);
    }
    
    return commonPrefix;
}


