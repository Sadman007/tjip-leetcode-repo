// TC: O(N)
// MC: O(1)
class Solution {
    
    public:
    int partition(vector<int>& nums, int left, int right){
        
        int pivot = right;
        int lt = left;
        int rt = right - 1;
        while (true) {
            while (lt <= right && nums[lt] < nums[pivot]) lt++;
            while (rt >= left && nums[rt] > nums[pivot]) rt--;
            if (lt > rt) break;
            swap(nums[lt++], nums[rt--]);
        } 
        swap(nums[lt], nums[pivot]);
        return lt;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0 , right = nums.size() - 1;
        while(true){
            int pos = partition(nums , left , right);
            if(pos + k == nums.size())
                break;
            else if( pos + k < nums.size()){
                left = pos + 1;
            }
            else
                right = pos - 1;
        }
        return nums[nums.size() - k];
    }
};