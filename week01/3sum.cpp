class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        if (len<3) return result;
        
        int i = 0;
        while(i < len-2){
            int j = i+1;
            int k = len-1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(nums[j] == nums[j+1] && j<k-1) j++;
                    while(nums[k] == nums[k-1] && j<k-1) k--;
                    j++;
                    k--;
                }
                else if(sum>0) k--;
                else j++;
            }
            while (i<len-3 && nums[i] == nums[i+1]) i++;
            i++;
        }

        return result;
    }
};