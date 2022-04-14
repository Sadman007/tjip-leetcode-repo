// TC: O(N^2)
// MC: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        
        for(int i = 0; i < (int)nums.size(); i++) {
            int a = nums[i];
            int L = i + 1;
            int R = (int)nums.size() - 1;
            int target = -a;
            while(L < R) {
                if(nums[L] + nums[R] > target) R--;
                else if(nums[L] + nums[R] < target) L++;
                else {
                    int b = nums[L];
                    int c = nums[R];
                    // remove duplicates
                    while(L + 1 < R && nums[L + 1] == b) {
                        L++;
                    }
                    // remove duplicates
                    while(L < R - 1 && nums[R - 1] == c) {
                        R--;
                    }
                    triplets.push_back({a, b, c});
                    L++;
                    R--;
                }
            }
            // remove duplicates 
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return triplets;
    }
};