//TC: O(|S|)
//MC: O(|S|)

class Solution {
public:
    bool isIsomorphic(string s, string t, int cnt = 0) {
        unordered_map<char, char> mp;

        for(int i = 0; s[i]; i++){
            if(mp.count(s[i]) && mp[s[i]] != t[i]) return 0;
            mp[s[i]] = t[i];
        }
        if(cnt == 1) return true;
        return isIsomorphic(t, s, 1);
    }
};
