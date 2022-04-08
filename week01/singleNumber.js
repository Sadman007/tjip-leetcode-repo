var singleNumber = function (nums) {
  let bucket = {};
  for (let char of nums) {
    if (bucket[char] === undefined) {
      bucket[char] = 1;
    } else {
      delete bucket[char];
    }
  }
  return Object.keys(bucket)[0];
};

console.log(singleNumber([2, 2, 1]));
