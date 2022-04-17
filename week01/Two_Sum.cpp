// TC: O(NlogN)
// MC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exist;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
            exist[nums[i]] = i;
        for(int i = 0; i < len; ++i)
        {
            if (exist.find(target - nums[i]) != exist.end() && i != exist[target-nums[i]])
                return {i, exist[target-nums[i]]};
        }
        return {0, 0};
    }
};
