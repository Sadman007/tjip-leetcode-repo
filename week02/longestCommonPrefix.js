var longestCommonPrefix = function (strs) {
  let commonPrefix = '';
  for (let i = 0; i < strs[0].length; i++) {
    if (strs.every((str) => str[i] === strs[0][i])) {
      commonPrefix += strs[0][i];
      continue;
    }
    break;
  }
  return commonPrefix;
};
