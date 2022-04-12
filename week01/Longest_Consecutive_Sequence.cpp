#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int longestSqn = 0;
        for (auto num : bucket)
        {
            if (bucket.count(num - 1) == 0)
            {
                int strtElement = num;
                while (bucket.count(strtElement))
                {
                    strtElement++;
                }
                longestSqn = max(longestSqn, strtElement - num);
            }
        }
        return longestSqn;
    }
};
