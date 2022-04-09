### 42. [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) `Hard`

---

#### Solution

```cpp
int trap(vector<int>& height) {
    int L = 0, R = height.size() - 1;
    int L_max = 0, R_max = 0, total_area = 0;

    while(L < R) {
        L_max = max(L_max, height[L]);
        R_max = max(R_max, height[R]);
        if (height[L] < height[R]) {
            total_area += L_max - height[L];
            L++;
        } else {
            total_area += R_max - height[R];
            R--;
        }
    }

    return total_area;
}
```

Time: `O(N)`

Space: `O(1)`

#### Explanation
