# 1554. Strings Differ by One Character (Medium)

Given a list of strings `dict` where all the strings are of the same length.

Return `true` if there are 2 strings that only differ by 1 character in the same index, otherwise return `false`.

### Example 1:

`Input: dict = ["abcd", "acbd", "aacd"]`

`Output: true`

`Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.`

### Example 2:

`Input: dict = ["ab","cd","yz"]`

`Output: false`

### Example 3:

`Input: dict = ["abcd","cccc","abyd","abab"]`

`Output: true`
 

### Constraints:

- The number of characters in `dict` is less than or equal to <code>10<sup>5</code>
- `dict[i].length == dict[j].length`
- `dict[i]` should be unique
- `dict[i]` contains only lowercase English letters.

**Follow up**: Could you solve this problem in `O(n * m)` where n is the length of `dict` and `m` is the length of each string?

### Function Signatures

#### C++
```c++
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        
    }
};
```

#### Java
```java
class Solution {
    public boolean differByOne(String[] dict) {
        
    }
}
```

#### C#
```cs
public class Solution {
    public bool DifferByOne(string[] dict) {
        
    }
}
```

#### Python3
```python
class Solution:
    def differByOne(self, dict: List[str]) -> bool:
```