#include "bits/stdc++.h"
using namespace std;
int maxProfit(vector<int>& prices)
{
	int left       = 0;
	int right      = 1;
	int max_profit = 0;
	while(right < prices.size())
	{
		if(prices[left] < prices[right])
		{
			int currPro = prices[right] - prices[left];
			max_profit  = max(currPro, max_profit);
		}
		else
		{
			left = right;
		}
		right ++;
	}
	return max_profit;
}
int main()
{
	vector<int> prices = {7,6,4,3,1};
	cout << maxProfit(prices);

	return 0;
}