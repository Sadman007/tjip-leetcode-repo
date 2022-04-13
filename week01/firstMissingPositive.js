var firstMissingPositive = function (nums) {
	let bucket = {};

	for (let i = 0; i < nums.length; i++) {
		bucket[nums[i]] = 1;
	}
	console.log(bucket);

	for (let j = 1; j <= nums.length + 1; j++) {
		if (bucket[j] == undefined) {
			return j;
		}
	}
	return 0;
};
firstMissingPositive([1, 2, 0]);
