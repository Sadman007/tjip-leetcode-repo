// TC: O(NlogM), where N = length of s, M = total number of characters in all words.
// MC: O(N)
class Solution {
public:

    bool isSubSeq(string &word, vector<vector<int> > &charToPos){
        int lastIdx = -1;
        for(int i = 0; i < word.size(); i++){
            int curr = word[i] - 'a';
            auto UB = upper_bound(charToPos[curr].begin(),charToPos[curr].end(), lastIdx);
            if(UB == charToPos[curr].end()) return false;
            lastIdx = *UB;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int> > charToPos(26);
        int cntSubSeq = 0;
        for(int i = 0; i < s.size(); i++){
            charToPos[s[i] - 'a'].push_back(i);
        }
        for(auto &word: words){
            cntSubSeq += isSubSeq(word, charToPos);
        }
        return cntSubSeq;
    }
};
