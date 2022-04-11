### 242. [Valid Anagram](https://leetcode.com/problems/valid-anagram/) `Easy`

---

#### Explanation

-   In the very beginning, I checked if the sizes two strings are equal or not. If the sizes are not equal, then the two strings are not anagrams. So I returned _false_.
-   Then I traversed both the strings and recorded the occurrence of each character in a hashmap. For each character in `s`, I increased the value by 1. For each character in `t`, I decreased the value by 1. If the value is not 0, then the two strings are not anagrams. So I returned _false_.

#### Complexity

Time: `O(N)`

Space: `O(N)`

#### Code

```cpp
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    unordered_map<int, int> bucket;

    for(int i = 0; i < s.size(); i++) {
        bucket[s[i]]++;
        bucket[t[i]]--;
    }

    for(auto bkt : bucket) {
        if(bkt.second != 0) return false;
    }

    return true;
}
```
