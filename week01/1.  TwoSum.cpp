// TC: O(N)
// MC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i = 0; i<nums.size(); i++){
            int remaining = target - nums[i];
            if(seen.count(remaining)){
                return {seen[remaining],i};
            }
            
            seen[nums[i]] = i;
        }
        
    return {};
        
    }
};