// TC: O(N)
// MC: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> window(256, 0);
        int longestSubstringLen = 0;
        int L = 0, R = 0, dupCnt = 0;
        while(R < s.size()) {
            window[s[R]]++;
            if (window[s[R]] > 1) {
                dupCnt++;
            }
            R++;
            while (dupCnt > 0) {
                window[s[L]]--;
                if (window[s[L]] == 1) {
                    dupCnt--;
                }
                L++;
            }
            longestSubstringLen = max(longestSubstringLen, R - L);
        }
        return longestSubstringLen;
    }
};
