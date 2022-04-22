//3. Longest Substring Without Repeating Characters
//TC: O(N)
//MC: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int lft = 0, rht = 0, mxLen = 0;
        while(s[rht]){
            freq[s[rht]]++;
            while(freq[s[rht]] > 1) {
                freq[s[lft]]--;
                lft++;
            }
            rht++;
            mxLen = max(mxLen, rht - lft);
        }
        return mxLen;
    }
};
