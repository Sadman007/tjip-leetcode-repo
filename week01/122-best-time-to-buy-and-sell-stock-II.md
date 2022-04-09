### 122. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) `Medium`

---

#### Code

```cpp
int maxProfit(vector<int>& prices) {
    int profit = 0;

    for(int i = 1; i < prices.size(); i++) {
        profit += max(prices[i] - prices[i-1], 0);
    }

    return profit;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
