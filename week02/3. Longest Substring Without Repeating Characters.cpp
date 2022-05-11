// TC = O(N)
// MC = O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int L = 0, R = 0, cnt = 0;
        int longestLength = 0;// given string can be empty
        while(R<s.size()){
            freq[s[R]]++;
            if(freq[s[R]]>1){
                cnt++;// cnt er value 2 mane--> 2 ta diff char repeat hoise
            }
            R++;

            while(cnt>0){
                freq[s[L]]--;
                if(freq[s[L]]==1){
                    cnt--;
                }
                L++;
            }
            longestLength = max(longestLength, R-L);
        }
        return longestLength;
    }
};
/*****************************************************/
// TC = O(N)
// MC = O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;
        int L = 0, longestSubString = 0;
        for(int R=0; R<s.size(); R++){
            while(seen.count(s[R])){
                seen.erase(s[L]);
                L++;
            }
            seen.insert(s[R]);
            longestSubString = max(longestSubString, R-L+1);
        }
        return  longestSubString;
    }
};
/*****************************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int longestLength = 0, latestOccurrence = 0;

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] != -1) {
                latestOccurrence = max(latestOccurrence, freq[s[i]] + 1);// bujhi nai ei line
            }
            freq[s[i]] = i; // idx rkhse freq a
            longestLength = max(longestLength, i - latestOccurrence + 1);
        }

        return longestLength;
    }
};
