### 136. [Single Number](https://leetcode.com/problems/single-number/) `Easy`

---

#### Code

```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(auto &num : nums) ans ^= num;
    return ans;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
