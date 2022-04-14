class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int cnt=0,m=0;
        for(auto num:s){
            int start;
            if(!s.count(num-1)){
                start=num;
            }
            while(s.count(start)){
                start++;
                cnt++;
            }
            m=max(m,cnt);
            cnt=0;
        }
        return m;
        
    }
};