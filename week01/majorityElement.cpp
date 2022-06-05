#include "bits/stdc++.h"
using namespace std;
int majorityElement(vector<int>& nums)
{
	int winner = 0, vote_count = 0;
	for (auto num : nums)
	{
		if(vote_count == 0)
		{
			winner = num; 
		}
		if(num == winner)
		{
			vote_count++;
		}
		vote_count--;
	}
	return winner;
}