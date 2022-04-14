class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k,i,count=0;
    for(i=0;i<nums.size();i++){
        if(nums[i]==0){
            count++;
        }
        else{
            k=nums[i-count];
             nums[i-count]=nums[i];
            nums[i]=k;
        }
    }
    }
};