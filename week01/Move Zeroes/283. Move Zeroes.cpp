class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        //Second Approach
        //Time : O(n)
        //Space : O(1)
        int count = 0;
        int zeros = 0;
        int j = nums.size()-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[count] = nums[i];
                count++;
            }
            else
            {
                zeros++;
            }
        }
        while(zeros--)
        {
            nums[j] = 0;
            j--;
        }
        
        //First Approach
        //Time : O(n^2)
        //Space : O(1)
      
        int i = 0;
        int j = nums.size()-1;
        while(i<=j)
        {
            if(nums[i] == 0)
            {
                for(int k=i; k<j; k++)
                {
                    nums[k] = nums[k+1];
                }
                nums[j] = 0;
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};

