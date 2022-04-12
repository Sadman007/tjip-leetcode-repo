#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0, totalArea = 0;
        while (l < r)
        {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if (height[l] < height[r])
            {
                totalArea += l_max - height[l];
                l++;
            }
            else
            {
                totalArea += r_max - height[r];
                r--;
            }
        }
        return totalArea;
    }
};