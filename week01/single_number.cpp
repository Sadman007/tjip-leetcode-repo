// TC: O(N)
// MC: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xOr = 0;
        for(auto num : nums)
        {
            xOr = xOr ^ num;
        }
        return xOr;
    }
};