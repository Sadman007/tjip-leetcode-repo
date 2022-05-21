// T - O(n), M - O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        for(int i=1;i<=nums.size()+1;i++){
            if(!seen.count(i)){
                return i;
            }
        }
        return 0;
    }
};
