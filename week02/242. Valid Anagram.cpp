//Time complexity -0(n
//space complexity- 0(s+t)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> str1;
        unordered_map<int, int> str2;
        for (auto &n: s) {
            str1[n]++;
        }
        for (auto &n: t) {
           str2[n]++;
        }
        return str1 == str2;
    }
};

