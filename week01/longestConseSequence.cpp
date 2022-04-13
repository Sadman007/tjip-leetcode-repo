#include "bits/stdc++.h"
using namespace std;
int longestConsecutive(vector<int>& nums){
	unordered_set<int>bucket(nums.begin(), nums.end());
	int longestSeqlen = 0;
	for(auto num : bucket)
	{
		if(bucket.count(num - 1) == 0)
		{
			int curr = num;
			while(bucket.count(curr))
			{
				curr++;
			}
			longestSeqlen = max(longestSeqlen,curr - num);
		}
	}
	return longestSeqlen;
};
int main()
{
	vector<int> nums = {100,4,200,1,3,2};
	cout << longestConsecutive(nums);
	return 0;
}