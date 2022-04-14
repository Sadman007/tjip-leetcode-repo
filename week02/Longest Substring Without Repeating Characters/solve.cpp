class Solution {
public:
    int lengthOfLongestSubstring(string s){
        
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        int maxLen = -1;
        map<char,int>seen;
        for(int i=0; i<s.length(); i++)
        {
            int left = i;
            int right = s.length();
            int current = 0;
            while(left<right)
            {
                seen[s[left]]++;
                if(seen[s[left]] > 1)
                {
                    current = seen.size();
                    maxLen = max(maxLen,current);
                    seen.clear();
                    break;
                }
                left++;
            }
        }
        return maxLen;
    }
};
