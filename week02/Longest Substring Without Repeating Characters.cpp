// TC : O(N)
// SC : O(1)

#include<algorithm>
#include<cstring>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=s.size();
        if(len==0)
            return 0;
        int res[300];
        memset(res,-1,sizeof res);
        res[s[0]]=0;
        
        int temp=1;
        int ans=1;
        for(int i=1;i<len;i++){
            
            if(res[s[i]]==-1)
                temp+=1;
            
            else if(res[s[i]]!=-1){
                temp=min(temp+1, i-res[s[i]]);
        
            }
            
            res[s[i]]=i;
            
            ans=max(ans, temp);
        }
        
        return ans;
    }
};
