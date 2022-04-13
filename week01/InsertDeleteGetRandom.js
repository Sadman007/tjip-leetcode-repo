var RandomizedSet = function () {
	this.nums = new Array();
	this.locs = new Object();
};

/**
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
	if (!(val in this.locs)) {
		this.nums.push(val);
		this.locs[val] = this.nums.length - 1;
		return true;
	}
	return false;
};

/**
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
	if (val in this.locs) {
		let loc = this.locs[val];
		let lastEl = this.nums[this.nums.length - 1];
		this.nums[loc] = lastEl;
		this.locs[lastEl] = loc;
		this.nums.pop();
		delete this.locs[val];
		return true;
	}
	return false;
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
	return this.nums[Math.floor(Math.random() * this.nums.length)];
};
