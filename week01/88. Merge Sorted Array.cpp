class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Time complexity -O(m+n)
        //space complexity -O(1)
        int i = m-1;
        int j = n-1;

        int last_index = m + n -1;

        while(i>=0 && j>=0){
            if(nums1[i] < nums2[j]){
                nums1[last_index--] = nums2[j--];

            }
            else{
                nums1[last_index--] = nums1[i--];
            }
        }

        while(i>=0){
            nums1[last_index--] = nums1[i--];
        }
        while(j>=0){
            nums1[last_index--] = nums2[j--];
        }

    }
};
