// T - O(n), M - O(1) --> Two pointer methods
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        for(int right=0;right<len;right++) {
            if(nums[right]!=0) {
                swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};
/**....................................................................**/

// T - O(n), M - O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int left = 0,cnt=0;
        for(int right=0;right<len;right++) {
            if(nums[right]!=0) {
                nums[left] = nums[right];
                left++;
            }
            else cnt++;
        }
        for(int i=0;i<cnt;i++){
            nums[left] = 0;
            left++;
        }

    }
};
