#include "bits/stdc++.h"
using namespace std;
int lengthOfLongestSubstring(string s)
{
	vector<int>freq(256, 0);
	int L = 0, R = 0, cnt = 0; 
	int longestLength = 0;
	while(R < s.size())
	{
		freq[s[R]]++;
		if(freq[s[R]] > 1)
		{
			++cnt;
		}
		R++;
		while(cnt > 0)
		{
			freq[s[L]]--;
			if(freq[s[L]] == 1)
			{
				--cnt;
			}
			L++;
		}
		longestLength = max(longestLength, R - L);
	}
	return longestLength;
}
