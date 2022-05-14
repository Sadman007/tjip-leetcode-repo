# 249. Group Shifted Strings

We can shift a string by shifting each of its letters to its successive letter.

- For example, `"abc"` can be shifted to be `"bcd"`.

We can keep shifting the string to form a sequence.

- For example, we can keep shifting `"abc"` to form the sequence: `"abc" -> "bcd" -> ... -> "xyz"`.

Given an array of strings strings, group all `strings[i]` that belong to the same shifting sequence. You may return the answer in **any order**.

### Example 1:

`Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]`

`Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]`

### Example 2:

`Input: strings = ["a"]`

`Output: ["a"]]`
 

### Constraints:

- `1 <= strings.length <= 200`
- `1 <= strings[i].length <= 50`
- `strings[i]` consists of lowercase English letters.


### Function Signatures
#### C++
```c++
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
    }
};
```

#### C#
```cs
public class Solution {
    public IList<IList<string>> GroupStrings(string[] strings) {
        
    }
}
```
#### JS

```js
/**
 * @param {string[]} strings
 * @return {string[][]}
 */
var groupStrings = function(strings) {
    
};
```

#### Python3
```python
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        
```
