var isValid = function (s) {
  let stack = [];
  let map = {
    ']': '[',
    '}': '{',
    ')': '('
  };
  for (let ch of s) {
    if (ch in map) {
      if (stack.length == 0) {
        return false;
      }
      if (map[ch] != stack.pop()) {
        return false;
      }
    } else {
      stack.push(ch);
    }
  }
  return stack.length > 0 ? false : true;
};
