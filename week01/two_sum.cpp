class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> check;
        for(int i=0; i<nums.size(); i++) {
            if(check.count(target - nums[i])) {
                res.push_back(check[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            check[nums[i]] = i;
        }
        return {};
    }
};
