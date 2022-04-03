class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int sz = nums.size();
        set<int> st(nums.begin(), nums.end());
        int mx = 0, cnt = 1;
        int chk = INT_MAX - 1;
        for (auto i : st)
        {
            if (chk + 1 == i)
            {
                cnt++;
            }
            else
            {
                if (cnt > mx)
                {
                    mx = cnt;
                }
                cnt = 1;
            }
            chk = i;
        }
        if (sz == 0)
            return 0;
        return max(mx, cnt);
    }
};

//////////////solution - 2//////////
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int longestSeqLen = 0;
        for (auto num : bucket)
        {
            if (bucket.count(num - 1) == 0)
            {
                // num -> starting element of sequence
                int curr = num;
                while (bucket.count(curr))
                {
                    curr++;
                }
                longestSeqLen = max(longestSeqLen, curr - num);
            }
        }
        return longestSeqLen;
    }
};