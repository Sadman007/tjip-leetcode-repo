// TC: O(N)
// MC: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqT(130, 0);
        
        for (auto ch : t) {
            freqT[ch]++;
        }
        
        int remCharOfT = t.size();
        int L = 0, R = 0, minLen = INT_MAX / 2, stIndex = -1;
        
        while (R < s.size()) {
            if (freqT[s[R]] > 0) remCharOfT--;
            freqT[s[R]]--;
            R++;
            
            while (remCharOfT == 0) {
                if (minLen > (R - L)) {
                    minLen = R - L;
                    stIndex = L;
                }
                if (freqT[s[L]] == 0) remCharOfT++;
                freqT[s[L]]++;
                L++;
            }
        }
        
        return stIndex == -1 ? "": s.substr(stIndex, minLen);
        
    }
};