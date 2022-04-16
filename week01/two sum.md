Solution:

class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer, Integer> resultMap = new HashMap<Integer, Integer>();
        
        for(int i = 0; i<nums.length; ++i) {
            int value = target - nums[i];
            
            if(resultMap.containsKey(value)) {
                return new int[] {resultMap.get(value), i};
            }
            resultMap.put(nums[i], i);
            
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}


***Learning