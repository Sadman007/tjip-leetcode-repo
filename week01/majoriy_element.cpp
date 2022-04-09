class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = nums[0], majority_count = 0;
        for(int i:nums) {
            if(i == winner)
                majority_count++;
            else
                majority_count--;
            if(majority_count < 0) {
                majority_count = 1;
                winner = i;
            }
        }
        return winner;
    }
};
