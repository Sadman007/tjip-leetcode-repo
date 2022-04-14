// TC: O(N)
// MC: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (find(nums.begin(), nums.end(), 1) == nums.end()) return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = max(1, nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(index < nums.size() && nums[index] > 0)
                nums[index] = -nums[index];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) return i + 1;
        }
        return nums.size() + 1;
    }
};