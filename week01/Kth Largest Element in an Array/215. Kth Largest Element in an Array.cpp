class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
    /*--- first Approach --*/        
        
    // Time O(nlogn)
    //Space O(1)
    sort(nums.begin(),nums.end(),greater<>());
    return nums[k-1];
        
   /*--- Second Approach --*/   
        
        
     //Time O(n^2)
    //Space O(1)
    int max = -1;
    for(int i=1; i<=k; i++)
    {
      max = -1;
      int idx = 0;
      for(int j=0; j<nums.size(); j++)
      {
        if(max<nums[j])
        {
          max = nums[j];
          idx = j;
        }
      }
     nums[idx] = -999999;
            
    }
    return max;
      
      
      
      /*--- Third Approach --*/   
       // Time O(n)
    //Space O(n)
      
       priority_queue<int>q;
       for(auto i:nums) q.push(i);
       while(k>1)
       {
           q.pop(); k--;
       }
       return q.top();
        
        
    }
};
