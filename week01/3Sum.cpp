class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i && nums[i]==nums[i-1])
                continue;
            
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int tm=nums[i]+nums[l]+nums[r];
                if(tm>0)
                     r--;
                else if(tm<0)
                     l++;
                else{
                    ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++,r--;
                }
            }
            
        }
        return ans;
    }
};
