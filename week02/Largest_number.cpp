class Solution {
public:

   static bool compare(int a, int b){

        if((to_string(a)+to_string(b)) > (to_string(b)+to_string(a)))
           return true;
         else
           return false;
    }
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end(),compare);

        string ans="";

        for(int i=0;i<nums.size();i++)
            ans+=to_string(nums[i]);

        if(ans<"1")
            ans="0";

        return ans;


    }
};
