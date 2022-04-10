Solution:

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer> > resultList = new ArrayList<>();
        
        Set<List<Integer>> setResult =  new HashSet<>();
        
        for(int i = 0; i < nums.length -2; ++i) {
            for(int j = 1; j < nums.length -1; ++j) {
                for(int k = 2; k < nums.length; ++k) {
                    if((nums[i] != nums[j]) && (nums[j] != nums[k]) && (nums[k] != nums[i])){
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> subList= new ArrayList<>();
                        subList.add(nums[i]);
                        subList.add(nums[j]);
                        subList.add(nums[k]);
                        setResult.add(subList);
                    }
                }
            }
            }
        }
        
        return new ArrayList<>(setResult);
    }
}

***Learning