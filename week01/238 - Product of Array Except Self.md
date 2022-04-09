### 238. [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

---

#### Solution

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size(), prefix = 1, postfix = 1; 
    vector<int> result(size, 1);

    for (int i = 0; i < size; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    for (int i = size - 1; i >= 0; i--) {
        result[i] *= postfix;
        postfix *= nums[i];
    }

    return result;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation

<img src="file:///C:/Users/SUSMOY%20SEN%20GUPTA/AppData/Roaming/marktext/images/2022-04-03-12-47-31-image.png" title="" alt="" data-align="center">
