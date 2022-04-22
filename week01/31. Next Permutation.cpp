class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int len = nums.size();

        if(len <= 2) return reverse(nums.begin(),nums.end());

        int pointer = len -2;

        while(pointer >=0 && nums[pointer] >= nums[pointer + 1]) pointer--;

        if(pointer == -1)
            return reverse(nums.begin(),nums.end());

        for(int i = len -1; i> pointer ;i-- ){
            if(nums[pointer] < nums[i]){
                int tmp = nums[i];
                nums[i] = nums[pointer];
                nums[pointer] = tmp;
                break;
            }
        }

       reverse(nums.begin() + pointer + 1 ,nums.end());


    }
};
