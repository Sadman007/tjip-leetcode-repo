### 169. [Majority Element](https://leetcode.com/problems/majority-element/) `Easy`

---

#### Code

```cpp
int majorityElement(vector<int>& nums) {
    int winner = 0, vote_count = 0, majority_cnt = 0;

    for(auto &num : nums) {
        if(!vote_count) winner = num;
        if(num == winner) vote_count++;
        else vote_count--;
    }

    for(auto &num : nums) {
        if(num == winner) majority_cnt++;
    }

    if(majority_cnt > nums.size() / 2) return winner;

    return -1;
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
