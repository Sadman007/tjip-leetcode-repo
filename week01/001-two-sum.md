### 1. [Two Sum](https://leetcode.com/problems/two-sum/) `Easy`

---

#### Solution

```cpp
vector<int> twoSum(vector<int>* nums, int target) {
    unordered_map<int, int> seen;

    for(int i = 0; i <= nums.size(); i++) {
        int remaining = target - nums[i];

        if(seen.count(remaining)) return {seen[remaining], i};
        seen[nums[i]] = i;
    }

    return {-1, -1};
}
```

#### Explanation

I took an unordered hash map. Then started iterating through every single element. Checked whether the remaining (`target - nums[i]`) element is found or not.
If it is found, then return the positions of the elements.
