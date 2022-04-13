



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        while(i<n){
            int  correctPos= nums[i];
            if(nums[i]>0&& nums[i]<=n && nums[correctPos-1] !=nums[i]){
                swap(nums[ correctPos-1], nums[i]);
                correctPos= nums[i];
            }
            else i+=1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};
