var isAnagram = function (s, t) {
	let len = s.length,
		fMap = new Int16Array(123);
	if (t.length !== len) return false;
	for (let i = 0; i < len; i++) fMap[s.charCodeAt(i)]++;
	for (let i = 0; i < len; i++) if (--fMap[t.charCodeAt(i)] < 0) return false;
	return true;
};
