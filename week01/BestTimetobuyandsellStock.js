/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let max_profit = 0;
  let min_so_far = prices[0];

  for (let i = 0; i < prices.length; i++) {
    min_so_far = Math.min(min_so_far, prices[i]);
    let profit = prices[i] - min_so_far;
    max_profit = Math.max(max_profit, profit);
  }

  return max_profit;
};
