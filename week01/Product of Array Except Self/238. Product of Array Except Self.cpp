


// First Approach 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
	    int zeros = 0;
        int product = 1;
        for(int i=0; i<nums.size(); i++)
	    {
		    if(nums[i] == 0)
            {	
                zeros++;
            }
            else
            {
                product = product*nums[i];
            }	
	    }
      
        vector<int>ans;
        if(zeros == 1)
        {
      	    for(auto i : nums)
		    {   
			    if(i == 0)
			    {
				    ans.push_back(product);
			    }
			    else
			    {
				    ans.push_back(0);
			    }
		    }
		    return ans;
	    }
        else if(zeros >= 2)
        {
      	    for(auto i : nums)
		    {
			    ans.push_back(0);
		    }
		    return ans;
	    }
        else
        {
	        for(auto i:nums)
	        {
		        ans.push_back(product/i);
	        }
	        return ans;
        }
    }
};


//Second Approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
	vector<int>ans;
      int preFix = 1;
      for(int i=0; i<nums.size(); i++)
	{
		ans.push_back(preFix);
            preFix = preFix*nums[i];
  	}
      int postFix = 1;
      for(int i = ans.size()-1; i>=0; i--)
      {
		ans[i] = ans[i]*postFix;
 		postFix = postFix*nums[i];
      }
      return ans;


    }
};


















