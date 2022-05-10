//76. Minimum Window Substring
//TC: O(|S|)
//MC: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0};
        for(char ch : t) freq[ch]++;
        int L = 0, R = 0, idx = -1, len_t = t.size();
        int remainingChar = len_t, mx_len = INT_MAX;

        while(s[R]){
            freq[s[R]]--;
            if(freq[s[R]] >= 0) remainingChar--;
            R++;

            while(freq[s[L]] < 0){
                freq[s[L]]++;
                if(freq[s[L]] == 1) remainingChar++;
                L++;
            }
            if(remainingChar == 0) {
                if(R - L < mx_len){
                    idx = L;
                    mx_len = R - L;
                }
            }
        }
        if(idx == -1) return "";
        return s.substr(idx, mx_len);
    }
};
