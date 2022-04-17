// TC: O(N^2)
// MC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L = 0, zero_cnt = 0, R = nums.size()-1;
        for(int i = R; i >= 0; --i)
        {
            if(nums[i] == 0) zero_cnt++;
            else break;
        }
        R -= zero_cnt;
        while (L <= R)
        {
            if (nums[L] == 0)
            {
                nums.erase(nums.begin() + L);
                nums.push_back(0);
                R--;
            }
            else L++;
        }
        return;
    }
};
