class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            unique = unique^nums[i];
        }
        return unique;
    }
};
