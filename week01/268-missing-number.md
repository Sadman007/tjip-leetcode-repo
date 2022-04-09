### 268. [Missing Number](https://leetcode.com/problems/missing-number/) `Easy`

---

#### Code

```cpp
int missingNumber(vector<int>& nums) {
    unordered_set<int> bucket(nums.begin(), nums.end());

    for(int i = 0; i <= nums.size() + 1; i++) {
        if(bucket.count(i) == 0) {
            return i;
        }
    }

    return 0;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
