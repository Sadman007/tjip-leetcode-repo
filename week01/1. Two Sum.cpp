// T - O(n^2), M - O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int sum = nums[i]+nums[j];
                if(sum==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
/**....................................................................**/

// T - O(n), M - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            int remaining = target-nums[i];
            if(seen.count(remaining)){
                return {i,seen[remaining]};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};

