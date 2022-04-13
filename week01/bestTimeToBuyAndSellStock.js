var maxProfit = function (prices) {
	let priceStart = prices[0];
	let maximum = 0;
	for (let i = 1; i < prices.length; i++) {
		if (priceStart > prices[i]) {
			priceStart = prices[i];
		}
		let profit = prices[i] - priceStart;
		maximum = Math.max(maximum, profit);
	}
	return maximum;
};
