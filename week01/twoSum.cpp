#include "bits/stdc++.h"
vector <int> towSum(vector<int> &sums, int target)
{
	unordered_map<int,int> seen;
	for(int i = 0; i < nums.size(); i++)
	{
		int remaining = target - nums[i];
		if(seen.count(remaining))
		{
			return {seen[remaining], i};
		}
		seen[nums[i]] = i;
	}
	return {};
}