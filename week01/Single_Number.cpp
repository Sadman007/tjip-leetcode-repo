class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0], len = nums.size();
        for(int i = 1; i < len; i++)
        {
            res = res^nums[i];
        }
        return res;
    }
};
