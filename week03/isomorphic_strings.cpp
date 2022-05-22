/**
Time: O(N), where N = length of string
Memory: O(1)
**/

class Solution {
public:
    bool isIsomorphic(string s, string t, int iteration_count = 0) {
        unordered_map<char, char> from;
        for (int i = 0; i < s.size(); i++) {
            if (from.count(s[i]) && from[s[i]] != t[i]) {
                return false;
            }
            from[s[i]] = t[i];
        }
        if (iteration_count == 0) return isIsomorphic(t, s, 1);
        return true;
    }
};