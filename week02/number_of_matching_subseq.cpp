// TC: O(M * logN), M = total length of all words, N = |s|
// MC: O(N)
class Solution {
public:
    bool isSubseq(string &word, vector<vector<int>>&charToPos) {
        int lastIdx = -1;
        for (auto &ch : word) {
            int curr = ch - 'a';
            auto it = lower_bound(charToPos[curr].begin(), charToPos[curr].end(), lastIdx);
            if (it == charToPos[curr].end()) return false;
            lastIdx = (*it) + 1;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cntSubseq = 0, i = 0;
        vector<vector<int>>charToPos(26);
        for (auto &ch : s) {
            charToPos[ch - 'a'].push_back(i++);
        }
        for (auto &word : words) {
            cntSubseq += isSubseq(word, charToPos);
        }
        return cntSubseq;
    }
};