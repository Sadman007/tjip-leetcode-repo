### 283. [Move Zeros](https://leetcode.com/problems/move-zeroes/) `Easy`

---

#### Code

```cpp
void moveZeroes(vector<int>& nums) {
    int last_non_zero = 0;

    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) nums[last_non_zero++] = nums[i];
    }

    for (int i = last_non_zero; i < nums.size(); i++) {
        nums[i] = 0;
    }

    return;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
