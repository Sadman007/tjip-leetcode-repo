class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        vector<vector<int>>res;
        if(arr.size()<4) return res;
        sort(arr.begin(),arr.end());
        int len = arr.size()-1;
        set<vector<int>>mySet;
        for(int i=0; i<arr.size()-2; i++)
        {
            for(int j=i+1; j<arr.size()-1; j++)
            {
                int nextPick = target - (arr[i]+arr[j]);
                int left = j+1;
                int right = len;
                
                while(left<right)
                {
                    long long checkSum = arr[left] + arr[right];
                    if(checkSum == nextPick)
                    {
                        mySet.insert({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        right--;
                    }
                    else if(checkSum < nextPick)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        vector<vector<int>>ans(mySet.begin(),mySet.end());
        return ans;
    }
};
