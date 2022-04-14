#include "bits/stdc++.h"
using namespace std;
int maxProfit(vector<int>& prices) {
	int mx = 0;
	for(int i = 0; i + 1 < prices.size(); i++)
	{
		if(prices[i + 1] < prices[i])
		{
			mx += prices[i + 1] - prices[i];
		}
	}
	return mx;
}
