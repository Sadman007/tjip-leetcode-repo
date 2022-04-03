class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int winner = 0, vote_cnt = 0;
        for (auto i : nums)
        {
            if (vote_cnt == 0)
            {
                winner = i;
            }
            if (i == winner)
            {
                vote_cnt++;
            }
            else
            {
                vote_cnt--;
            }
        }
        return winner;
    }
};

//////////////solution - 2//////
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx = 0,res;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>mx){
                mx = mp[nums[i]];
                res = nums[i];
            }
        }
        return res;
    }
};