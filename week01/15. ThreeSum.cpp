// TC: O(N^2)
// MC: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i = 0; i<len - 2; i++){
            
            if(i == 0 || nums[i] != nums[i-1]){
                
                int l = i+1 , r = len - 1;
                
                while(l <r ){
                    
                    int sum = nums[i] + nums[l] + nums[r];
                    
                    if(sum == 0){
                        result.push_back({nums[i] , nums[l] , nums[r]});
                        while(l < r && nums[l] == nums[l+1])l++;
                        while(l < r && nums[r] == nums[r-1])r--;
                        
                       l++;
                       r--;
                    }
                  else if(sum > 0)r--;
                  else l++;
                    
                }
                
            }
        }
        return result;
    }
};