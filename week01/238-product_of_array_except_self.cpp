class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (nums[i] != 0)
            {
                product = product * nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (mp.count(0))
                {
                    nums[i] = 0;
                }
                else
                {
                    nums[i] = product / nums[i];
                }
            }
            else
            {
                if (mp[0] == 1)
                {
                    nums[i] = product;
                }
                else
                {
                    nums[i] = 0;
                }
            }
        }
        return nums;
    }
};