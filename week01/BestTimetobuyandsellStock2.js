/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let left = 0;
  let right = 1;
  let result = 0;

  while (left < prices.length && right < prices.length) {
    if (prices[left] > prices[right]) {
      left++;
    } else {
      result = Math.max(result, prices[right] - prices[left]);
      right++;
    }
  }
  return result;
};
