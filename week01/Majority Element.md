Solution:

class Solution {
    public int majorityElement(int[] nums) {
        int result = nums[0];
        int count = 0;
        
        for(int i = 0; i<nums.length; ++i) {
            if(count == 0) {count++;result = nums[i];}
            else{
                if(result == nums[i]) count++;
                else {
                    count--;
                }
            }
        }
        return result;
    }
}

***Learning
it can solveable by using HashMap with extra memory