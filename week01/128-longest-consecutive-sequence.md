### 128. [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) `Medium`

---

#### Code

```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> bucket(nums.begin(), nums.end());
    int lcs = 0;

    for(auto num : nums) {
        if(bucket.count(num - 1) == 0) {
            int curr = num;
            while(bucket.count(curr)) curr++;
            lcs = max(lcs, curr - num);
        }
    }

    return lcs;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
