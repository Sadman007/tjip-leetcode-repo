 class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector< vector< int > > result;

        int n=nums.size();
  	    if(n<0)
    		return result;
        sort(nums.begin(), nums.end());


        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) 
                continue;
	        for(int j=i+1;j<n;j++)
            {
			    int remainingSum=target-nums[i]-nums[j];

        		int x= j+1;
		    	int y= n-1;
			    while( x <y)
                {
    				int curSum= nums[x] + nums[y];

        			if(curSum > remainingSum)
		        	{
    	      	        y--;
			        }
                    else if(curSum < remainingSum)
                    {
				        x++;
                    }
                    else{
	
                  	    int thirdSum=nums[x];
                        int forthSum=nums[y];
                        result.push_back({nums[i], nums[j], nums[x],nums[y]});
	                    while(x<y && nums[x]==thirdSum) 
                        {
                            x++;
                        }
                        while(x<y && nums[y]==forthSum) 
                        {
                            y--;
                        }

	
                    }

                }
            while(j<n-1 && nums[j+1] == nums[j]) 
            {
                ++j;
            }

        }

      }
      return result;
    }
};



