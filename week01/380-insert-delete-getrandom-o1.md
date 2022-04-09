### 380. [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) `Easy`

---

#### Code

```cpp
vector<int> a;
unordered_map<int,int> m;

RandomizedSet() {}

bool insert(int val) {
    if(m.find(val)!=m.end())
        return false;
    else {
        a.push_back(val);
        m[val]=a.size()-1;
        return true;
    }
}

bool remove(int val) {
    if(m.find(val)==m.end())
        return false;
    else {
        int last=a.back();
        a[m[val]]=a.back();
        a.pop_back();
        m[last]=m[val];
        m.erase(val);
        return true;
    }
}

int getRandom() {

    return a[rand()%a.size()];
}
```

#### Complexity

Time: `O(N)`

Space: `O(1)`

#### Explanation
