var majorityElement = function (nums) {
	let winner = 0;
	let vote_count = 0;

	for (let i = 0; i < nums.length; i++) {
		if (vote_count == 0) {
			winner = nums[i];
		}
		if (nums[i] == winner) {
			vote_count++;
		} else {
			vote_count--;
		}
	}
	return winner;
};
