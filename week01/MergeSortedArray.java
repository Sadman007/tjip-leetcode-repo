public void merge(int[] nums1, int m, int[] nums2, int n) {
        int left = 0, right = 0, core = 0;
        int[] temp = new int[nums1.length];
        
        for(int i = 0; i<temp.length;i++) temp[i] = nums1[i];
        
        while(left < m && right < n){
            if(temp[left] >= nums2[right]){
                nums1[core++] = nums2[right++];
            }else nums1[core++] = temp[left++];
        }
        
        while(left < m) nums1[core++] = temp[left++];
        while(right < n) nums1[core++] = nums2[right++];
        
    }
