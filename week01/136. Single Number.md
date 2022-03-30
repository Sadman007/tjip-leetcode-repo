Solution:

 class Solution {
    public int singleNumber(int[] nums) {
        
        int result = 0;
        for(int i = 0; i<nums.length; ++i) {
            result ^= nums[i]; // XOR = 8 XOR 8 = 0; 0 XOR 1 = 1;
        }
        return result;
    }
}

***Learning
Use of XOR