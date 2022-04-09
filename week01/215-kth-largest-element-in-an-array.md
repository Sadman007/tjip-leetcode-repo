### 215. [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) `Medium`

---

#### Code

```cpp
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int> ());

    return nums[k-1];
}
```

#### Complexity

Time: `O(N logN)`

Space: `O(1)`

#### Explanation
