#include "bits/stdc++.h"
using namespace std;
void moveZeroes(vector<int>& nums)
{
	int list = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] != 0)
		{
			nums[list++] = nums[i];
		}
	}
	while(list < nums.size())
		{
			nums[list++] = 0;
		};
}
int  main()
{
	vector<int> nums = {0,1,0,3,12};
	moveZeroes(nums);
	return 0;
}