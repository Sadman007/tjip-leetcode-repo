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
            if(i>0 and arr[i] == arr[i-1]) continue;
            for(int j=i+1; j<arr.size()-1; j++)
            {
                if(j>i+1 and arr[j] == arr[j-1]) continue;
                
                int nextPick = target - (arr[i]+arr[j]);
                int left = j+1;
                int right = len;
                
                while(left<right)
                {
                    long long checkSum = arr[left] + arr[right];
                    if(checkSum == nextPick)
                    {
                        res.push_back({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        while(arr[left-1] == arr[left] and left<right ) 
                        {
                            left++;
                        } 
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
        return res;
    }
};
