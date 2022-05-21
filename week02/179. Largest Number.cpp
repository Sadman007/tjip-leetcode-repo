// check notes(leetcode)
// https://youtu.be/qEIGhVtZ-sg
// TC : O(N*K*logN)
// MC : O(N) where, N = number of strings, K = avg length of a string

bool cmp(int &a, int &b){
    string sa = to_string(a);
    string sb = to_string(b);
    string sab = sa + sb;
    string sba = sb + sa;
    return sab > sba;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res = "";
        for(int i = 0; i < nums.size(); i++){
            if(res=="" && nums[i]==0 && i+1<nums.size()) continue;//Input = [0,0], Output = "00", Expected = "0"
            res += to_string(nums[i]);
        }
        return res;
    }
};
