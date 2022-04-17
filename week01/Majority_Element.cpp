// TC: O(N)
// MC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, cnt = 0, len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            if (cnt == 0){
                major = nums[i];
                cnt++;
            }
            else{
                if(major == nums[i]) cnt++;
                else cnt--;
            }
        }
        return major;
    }
};
