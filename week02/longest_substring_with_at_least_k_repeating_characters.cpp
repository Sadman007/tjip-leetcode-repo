// TC: O(26 * N) ~ O(N)
// MC: O(1)
class Solution {
public:
    int findLongestSubstringWithKUniqueChar(string s, int k, int uniqueChar) {
        int L = 0, R = 0, longestLen = 0, uniqueCharCnt = 0, freqAtLeastK = 0;
        vector<int> freq(130, 0);
        while (R < s.size()) {
            freq[s[R]]++;
            uniqueCharCnt += freq[s[R]] == 1;
            freqAtLeastK += freq[s[R]] == k;
            R++;
            while (uniqueCharCnt > uniqueChar) {
                freq[s[L]]--;
                uniqueCharCnt -= freq[s[L]] == 0;
                freqAtLeastK -= freq[s[L]] == (k - 1);
                L++;
            }
            if (uniqueCharCnt == freqAtLeastK) {
                longestLen = max(longestLen, R - L);
            }
        }
        return longestLen;
    }
    int longestSubstring(string s, int k) {
        int longestLen = 0;
        for (int uniqueChar = 1; uniqueChar <= 26; uniqueChar++) {
            longestLen = max(longestLen, findLongestSubstringWithKUniqueChar(s, k, uniqueChar));
        }
        return longestLen;
    }
};