// TC: O(N^3)
// MC: O(N)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        vector< vector<int> > quadruplets;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int ab = target-(nums[i] + nums[j]);
                int k = j + 1;
                int l = n - 1;
                while(k < l && k >= 0 && l < n)
                {
                    if(nums[k] + nums[l] == ab)
                    {
                        while(k < l && nums[k] == nums[k + 1]) ++k;
                        while(k < l && nums[l] == nums[l - 1]) --l;
                        quadruplets.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                    }
                    else if(nums[k] + nums[l] < ab)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return quadruplets;
    }
};
