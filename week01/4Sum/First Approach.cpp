class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        vector<vector<int>>res;
        if(arr.size()<4) return res; // if the size of given array is less then 4 then its impossible to find ans,,, so return empty array
        sort(arr.begin(),arr.end()); // sorting array for make it easy to calculate and track integers and applying 2 pointer approach
        int len = arr.size()-1;
        set<vector<int>>mySet;  /// taking set to store unique results of vectors
        for(int i=0; i<arr.size()-2; i++)
        {
            for(int j=i+1; j<arr.size()-1; j++)
            {
                int nextPick = target - (arr[i]+arr[j]);  // make a primary target to reach goal and find final target
                int left = j+1;
                int right = len;
                
                while(left<right)
                {
                    long long checkSum = arr[left] + arr[right]; // make a sum to check if it satisfy our nextpick
                    if(checkSum == nextPick)
                    {
                        mySet.insert({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        right--;
                    }
                    else if(checkSum < nextPick) //if desired value is greater than current sum then increment left pointer to get bigger integer as it is sorted in 
                    {                             //increasing order
                        left++;
                    }
                    else
                    {               // if less , then decrement the right counter
                        right--;
                    }
                }
            }
        }
        vector<vector<int>>ans(mySet.begin(),mySet.end());
        return ans;
    }
};
