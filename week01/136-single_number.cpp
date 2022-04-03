class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i : nums)
        {
            if (s.count(i) == 1)
            {
                s.erase(i);
            }
            else
            {
                s.insert(i);
            }
        }
        return *s.begin();
    }
};

//////////////solution - 2/////////
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for (auto i : freq)
        {
            if (i.second == 1)
            {
                return i.first;
            }
        }
        return 0;
    }
};