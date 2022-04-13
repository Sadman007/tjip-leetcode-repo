var maxProfit = function (prices) {
	if (prices.length === 1) {
		return prices[0];
	}
	let result = 0;

	prices.forEach(element => {
		result = result ^ element;
	});

	return result;
};
