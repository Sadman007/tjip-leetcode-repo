class Solution {
public:
    bool isAnagram(string s, string t) {
            
        if(s.length() != t.length()) return false;
        map<char,int>bucket1; //space O(26)
        map<char,int>bucket2; //space O(26)
        for(int i=0; i<s.length(); i++)
        {
            bucket1[s[i]]++;
            bucket2[t[i]]++;
        }
        for(auto it:bucket1) //time O(26)
        {
            char ch = it.first;
            int count = it.second;
            if(bucket2[ch] != count)
            {
                return false;
            }
        }
        return true; 
        
    }
};
