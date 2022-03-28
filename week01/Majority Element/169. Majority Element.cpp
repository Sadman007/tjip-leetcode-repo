class Solution {
public:
    int majorityElement(vector<int>& nums) {
 
/******************** first Approach ************************/
        

//Time Complexity = O(n)
//Space Complexity = O(n)
           
        int mx = -1;
        int maxTimes;
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            ++mp[nums[i]];
            if(mx<=mp[nums[i]])
            {
                mx = mp[nums[i]];
                maxTimes = nums[i];
            }
        }
        return maxTimes;
        
        
       
/******************** Second Approach ************************/

        
//Time Complexity = O(n)
//Space Complexity = O(1) 
           int appear = 0;
           int majority = 0;
           for(int i=0; i<nums.size(); i++)
           {
               if(appear == 0)
               {
                   majority = nums[i];
                   appear++;
               }
               else if(majority != nums[i])
               {
                   appear--;
               }
               else
               {
                   appear++;
               }
           }
           return majority;
    }
};
