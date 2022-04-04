class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        
        if(nums.size() == 1) return;
        //lest check if the last integer is greater than the previous integer, if it is then just swap and we will get 
        //the next permutation of our array
        int len = nums.size();
        if(nums[len-1]>nums[len-2])
        {
            swap(nums[len-1],nums[len-2]);
            return;
        }
        int pickUp = -1;
        //First we have to check if the array is already in ascending order if its not then we will get a pickUp index
        for(int i=1; i<len; i++)
        {
            if(nums[i]>nums[i-1])
            {
                pickUp = i;
            }
        }
        if(pickUp == -1) // if array is already sorted in descending  order
        {
            int j = len;
            for(int i=0; i<len/2; i++)
            {
                swap(nums[i],nums[--j]);
            }
            return;
        }
        
        //Now Lets pick the index of the integer that we should set in such a place in this array that it will be 
        //the next permutation which is the minimum possible and maximum from previous
        int pick = pickUp;
        for(int i=pickUp; i<len; i++)
        {
            if(nums[i] > nums[pickUp-1] and nums[i]<nums[pickUp])
            {
                pick = i;
            }
        }
        //Now Swap these 2 values
        swap(nums[pick],nums[pickUp-1]);
        sort(nums.begin()+pickUp,nums.end());
    }
};
