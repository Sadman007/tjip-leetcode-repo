Solution:

class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;
        
        Set addNumberToSet = new TreeSet<>();
        for(int i = 0; i <nums.length; ++i) {
            addNumberToSet.add(nums[i]);
        }
        
        int n = addNumberToSet.size();
        int arr[] = new int[n];
        
        int i = 0;
          for (var x : addNumberToSet) {
              arr[i++] = (int)x;
          }
        int result = 1;        int sresult = 1;

        int maxResut = 1;
        boolean  visit = false;
        
        for(int k = 0; k < n - 1; ++k) {
           if((arr[k]+1) ==  arr[k +1]) {
               visit = false;
               System.out.println(arr[k]);
               result += 1;
               sresult += 1;
           }else {
               visit = true;
               maxResut = result;
               result = 1;
           }
        }
              System.out.println(result);              System.out.println(maxResut);

        return visit ? sresult : Math.max(result, maxResut);
    }
}

***Learning