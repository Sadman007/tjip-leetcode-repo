/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {
  const bucket = new Set(nums);
  for (let i = 1; i <= nums.length + 1; i++) {
    if (!bucket.has(i)) {
      return i;
    }
  }
  return 0;
};
