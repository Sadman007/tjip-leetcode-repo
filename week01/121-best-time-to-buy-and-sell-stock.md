### 121. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) `Easy`

---

#### Code

```cpp
int maxProfit(vector<int>& prices) {
    int local_sum = 0, maxProfit = 0;

    for(int i = 0; i < prices.size() - 1; i++)
    {
        local_sum += prices[i+1] - prices[i];
        if(local_sum < 0) local_sum = 0;
        maxProfit = max(maxProfit, local_sum);
    }

    return maxProfit;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
