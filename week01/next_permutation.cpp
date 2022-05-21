// TC: O(N)
// MC: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, n = nums.size();
        for(i = n - 1; i > 0; i--)
        {
            if(nums[i] > nums[i - 1]) break;
        }
        int L = i - 1;
        if(L < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        /// find the right larger item than nums[L] from [i..n - 1]
        for(i = n - 1; i >= 0; i--)
        {
            if(nums[L] < nums[i]) 
            {
                break;
            }
        }
        int R = i;
        swap(nums[L], nums[R]);
        reverse(nums.begin() + L + 1, nums.end());
    }
};