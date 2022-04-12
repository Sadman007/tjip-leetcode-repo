#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, minimum = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            // for(int j=i+1; j<prices.size(); j++)
            //   if(prices[i] < prices[j])
            //  profit = max(profit, prices[j]-prices[i]);

            minimum = min(minimum, prices[i]);
            profit = max(profit, (prices[i] - minimum));
        }
        return profit;
    }
};