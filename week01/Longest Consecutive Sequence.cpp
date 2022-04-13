class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Set;
       
        for(int i : nums)
            Set.insert(i);
        int ans=0, mxLen=0; 
        
        int i=0;
        for(int num : Set)
        {
            if(i && Set.count(num-1))
                continue;
            int cnt=1;
            int curValue=num;
            while(Set.count(curValue+1)){
                
                curValue+=1;
                cnt+=1;

            
            }
            i=1;
            
            mxLen=max(mxLen,cnt);
            
        }
                                               
        return mxLen;
        
    }
};


