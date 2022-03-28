// Time complexity O(n * n)
//Space complexity O(1)

var maxProfit = function (prices) {
  let maximum = 0;
  for (let i = 0; i < prices.length; i++) {
    for (let j = i; j < prices.length; j++) {
      let profit = prices[j] - prices[i];
      maximum = Math.max(maximum, profit);
    }
  }
  return maximum;
};

var maxProfitOptimized = function (prices) {
  let startPrice = prices[0];
  let maximum = 0;
  for (let i = 1; i < prices.length; i++) {
    if (startPrice > prices[i]) {
      startPrice = prices[i];
    }
    let profit = prices[i] - startPrice;
    maximum = Math.max(maximum, profit);
  }
  return maximum;
};

let prices = [7, 6, 4, 3, 1];

console.log(maxProfit(prices));

console.log(maxProfitOptimized(prices));
