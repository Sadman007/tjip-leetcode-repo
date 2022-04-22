// TC: O(N)
// MC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left = 0;

        for(int right = 0; right< nums.size(); right++){
            if(nums[right] != 0){
                nums[left] = nums[right];
                left++;

            }
         }
        while(left<nums.size()){
                nums[left++]  = 0;
            }
    }
};
