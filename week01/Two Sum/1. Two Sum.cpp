class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      
       //NAZMUL HAQUE NAHIN  
      
       ///Explanation :
       /*
       first we saw that 
       we need find such two integers from our given array that their sum will be exactly equal to our target value
       then we should return their 2 indices in any order as vector ;
       
       theme 1 : 
       if we apply bruteforce method and take a single integer then make sum for rest of the elements of our given array then
       it should cost O(n^2) time complexity and its not optimal solution 
       
       
       theme 2 : 
       here we can take a container like MAP and keep every single element of our array which is not equal to our (target - current)
       we will be looking for such an element in our map which is equal to the difference between our current element and target element;
       if we find such 2 then just store their index no in 2 different variable and break the loop 
       then return those values as a vector
       
       */
        
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
