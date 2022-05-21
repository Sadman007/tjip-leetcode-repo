// TC: O(N)
// MC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>seen;
        for(int i = 0; i < nums.size(); i++)
        {
            int v = target - nums[i];
            if(seen.find(v) != seen.end())
            {
               return {seen[v], i}; 
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};