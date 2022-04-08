var majorityElement = function (nums) {
  let count = 0;
  let res = 0;

  for (let i = 0; i < nums.length; i++) {
    let current = nums[i];
    if (count === 0) {
      res = current;
    }

    if (res === current) {
      count++;
    } else {
      count--;
    }
  }

  return res;
};
