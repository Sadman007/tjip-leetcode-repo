public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int product = nums[n-1];
        
        result[0] = nums[0];
        for(int i=1; i<n; i++){
            result[i] = result[i-1] * nums[i];
        }
        
        
        result[n-1] = result[n-2];
        for(int i=n-2; i>0; i--){
            result[i] = result[i-1] * product;
            product*=nums[i];
        }
        result[0] = product;
        
        return result;
    }
