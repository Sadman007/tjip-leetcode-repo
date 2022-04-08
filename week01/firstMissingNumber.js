var firstMissingPositive = function (nums) {
  let bucket = {};
  for (let c = 0; c < nums.length; c++) {
    bucket[nums[c]] = 1;
  }
  for (let i = 1; i <= nums.length + 1; i++) {
    if (bucket[i] === undefined) {
      return i;
    }
  }
  return 0;
};
