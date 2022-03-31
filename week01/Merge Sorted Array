nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

      while(m>0 and n>0 ) {
        if(nums1[m-1] > nums2[n-1]){
          m--;
          nums1[m+n]= nums1[m];
      }
      else {
        n--;
        nums1[m+n]= nums2[n];
      }
      }        
      if(n>0){
      n--;
          nums1[m+n]= nums2[n];

      }
    }
};




