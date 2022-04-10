Solution:

class Solution {
    public void moveZeroes(int[] nums) {
        int k= 0;
        for(int i = 0;  i<nums.length; ++i){
            if(nums[i] != 0) {
                int temp =  nums[i];
                // nums[i] = nums[k + 1]; create error and make it overflow
				nums[i] = nums[k];
                nums[k++] = temp;
            }
        }
    }
}

***Learning
1. check the array index bound 
2. if we move zero then check last then check it in != 