// T - O(n^2), M - O(n) --> give AC once somehow...otherwise give TLE on 318 no test case always out of total 318 test cases
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int leftP,rightP;
        map<vector<int>,int> combinations;
        vector<vector<int> > result;

        for(int i=0;i<len-2;i++){
            leftP = i+1, rightP = len-1;
            while(leftP<rightP){
                int sum = nums[i] + nums[leftP] + nums[rightP];
                if(sum == 0 && combinations[{nums[i],nums[leftP],nums[rightP]}]==0){
                    combinations[{nums[i],nums[leftP],nums[rightP]}]++;
                    result.push_back({nums[i], nums[leftP], nums[rightP]});
                    leftP++;

                }
                else if(sum > 0){
                    rightP--;
                }
                else{
                    leftP++;
                }

            }
        }
        return result;
    }
};

/**....................................................................**/

// T - O(n^2), M - O(n) --> AC always('map' solution)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int leftP,rightP;
        map<vector<int>,int> combinations;
        vector<vector<int> > result;

        for(int i=0;i<len-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;// adding this line gives AC to the first soln
            leftP = i+1, rightP = len-1;
            while(leftP<rightP){
                int sum = nums[i] + nums[leftP] + nums[rightP];
                if(sum == 0 && combinations[{nums[i],nums[leftP],nums[rightP]}]==0){
                    combinations[{nums[i],nums[leftP],nums[rightP]}]++;
                    result.push_back({nums[i], nums[leftP], nums[rightP]});

                    leftP++;

                }
                else if(sum > 0){
                    rightP--;
                }
                else{
                    leftP++;
                }

            }
        }
        return result;
    }
};
/**....................................................................**/

// T - O(n^2), M - O(n) --> AC always(two pointer solution)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int leftP,rightP;
        vector<vector<int> > result;

        for(int i=0;i<len-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            leftP = i+1, rightP = len-1;
            while(leftP<rightP){
                int sum = nums[i] + nums[leftP] + nums[rightP];
                if(sum == 0 ){
                    result.push_back({nums[i], nums[leftP], nums[rightP]});

                    leftP++;
                    while(nums[leftP]==nums[leftP-1] && leftP<rightP) leftP++;

                }
                else if(sum > 0){
                    rightP--;
                }
                else{
                    leftP++;
                }

            }
        }
        return result;
    }
};
/**....................................................................**/

// T - O(n^2), M - O(n) --> AC always('set' solution)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int leftP,rightP;
        set<vector<int> > comb;
        vector<vector<int> > result;
        int target = 0;
        for(int i=0;i<len;i++){
            int remaining = target - nums[i];
            int l = i+1,r = len-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum ==0){
                    comb.insert({nums[i],nums[l],nums[r]});
                    l++,r--;
                }
                else if(sum>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        for(vector<int> v: comb){
            result.push_back({v});
        }
        return result;
    }
};
