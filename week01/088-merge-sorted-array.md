### 88. [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) `Easy`

---

#### Code

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last_idx = m + n - 1;

    while (m > 0 && n > 0) {
        if(nums1[m-1] < nums2[n-1]) {
            nums1[last_idx] = nums2[n-1];
            n--;
        } else {
            nums1[last_idx] = nums1[m-1];
            m--;
        }
        last_idx--;
    }

    while(n > 0) {
        nums1[last_idx] = nums2[n-1];
        n--, last_idx--;
    }

    return;
}
```

#### Complexity

Time: `O(M + N)`

Space: `O(1)`

#### Explanation
