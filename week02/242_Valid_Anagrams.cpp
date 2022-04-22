//242. Valid Anagram
//TC: O(|S|)
//MC: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_cnt[26] = {0}, t_cnt[26] = {0};
        for(int i = 0; s[i]; i++) s_cnt[s[i]-'a']++;
        for(int i = 0; t[i]; i++) t_cnt[t[i]-'a']++;
        for(int i = 0; i < 26; i++){
            if(s_cnt[i] != t_cnt[i]) return 0;
        }
        return 1;
    }
};
