class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int i = 0;
        int len = s.length();
        if(k>len) return 0;
        if(k <= 1) return len;
        
        map<char,int>freq;
        for(auto ch : s) freq[ch]++;
        
        while(i<len and freq[s[i]] >= k)
        {
            i++;
        }
        if(i>=len-1) return i;
        
        int sub1 = longestSubstring(s.substr(0,i), k);
        cout<<sub1<<" ";
        while(i<len and freq[s[i]]<k) 
        {
            i++;
        }
        int sub2 = (i<len)? longestSubstring(s.substr(i), k) : 0;
        
        
        return max(sub1,sub2);
        
    }
};

    
