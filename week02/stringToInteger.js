var myAtoi = function (str) {
  if (!str) {
    return 0;
  }
  const INT_MAX = 2147483647;
  const INT_MIN = -2147483648;
  str = str.trim();
  let i = 0;
  const isNegative = str[0] === '-';
  const isPositive = str[0] === '+';
  if (isNegative) {
    i++;
  } else if (isPositive) {
    i++;
  }
  let number = 0;
  while (i < str.length && str[i] >= '0' && str[i] <= '9') {
    number = number * 10 + (str[i] - '0');
    i++;
  }
  number = isNegative ? -number : number;
  if (number < INT_MIN) {
    return INT_MIN;
  }
  if (number > INT_MAX) {
    return INT_MAX;
  }
  return number;
};
