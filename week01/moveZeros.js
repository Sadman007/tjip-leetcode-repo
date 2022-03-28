// Space complexity O(n)

var moveZeroes = function (nums) {
  let moved = [];
  let track = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] != 0) {
      moved.push(nums[i]);
      track++;
    }
  }
  let remain = nums.length - track;
  for (i = 0; i < remain; i++) {
    moved.push(0);
  }
  return moved;
};

var moveZeroesOptimized = function (nums) {
  let left = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      let temp = nums[i];
      nums[i] = nums[left];
      nums[left] = temp;
      left++;
    }
  }
  return nums;
};

let nums = [0, 1, 0, 3, 12];
console.log(moveZeroes(nums));
