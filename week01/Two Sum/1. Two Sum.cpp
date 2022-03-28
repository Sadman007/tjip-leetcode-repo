class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      
     
        
        map<int,int>mp;
        
        int a = -1;
        int b = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            int diff = target-nums[i];
            if(mp.count(diff) > 0)
            {
                a = mp[diff];
                b = i;
                break;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        
        return {a,b};
    }
};

///Time Complexity : O(n)
///Space Complexity : O(n
