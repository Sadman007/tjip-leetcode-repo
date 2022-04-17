// TC: O(NlogN)
// MC: O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 1; i <= len + 1; i++)
        {
            if(bucket.count(i) == 0)
            {
                return i;
            }
        }
        return 0;
    }
};
