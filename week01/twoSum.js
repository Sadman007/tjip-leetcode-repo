// time complexity O(n^2)

var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = 1; j < nums.length; j++) {
      if (nums[i] + nums[j] == target) {
        return [i, j];
      }
    }
  }
  return [];
};

// Time complexity O(n)
// Space complexity O(n)

var twoSumOptimized = function (nums, target) {
  let seen = {};
  for (let i = 0; i < nums.length; i++) {
    let remaining = target - nums[i];
    if (seen.hasOwnProperty(remaining)) {
      return [seen[remaining], i];
    }
    seen[nums[i]] = i;
  }
  return [];
};

let nums = [3, 3];
let target = 6;

console.log(twoSum(nums, target));
console.log(twoSumOptimized(nums, target));
