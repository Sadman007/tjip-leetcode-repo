class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;  i<nums.size()-2; i++)
        {
            int constant = nums[i];
            if(i!=0)
            {
                if(constant == nums[i-1]) continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                if(nums[left] + nums[right] + constant == 0)
                {
                    ans.push_back({constant,nums[left],nums[right]});
                    while(left<right and nums[left] == nums[left+1])
                    {
                        left++;
                    }
                    while(left<right and nums[right] == nums[right-1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] + constant > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};





