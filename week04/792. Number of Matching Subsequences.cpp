//TC: O(Nlog|S|)  -> N := Σ|words[i]| * 26,  |S| := s.length
//MC: O(N)

class Solution {
public:
    class trieNode{
        public:
        int cntWord;
        trieNode *next[26];
        trieNode(){
            cntWord = 0;
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };

    trieNode *rootNode;
    vector<int> position[26]; // to save all position for i'th character

    void insertWord(string &word){
        trieNode *curNode = rootNode;
        for(char &ch : word){
            int edgeValue = ch - 'a';
            if(curNode->next[edgeValue] != NULL){ /// path exist
                curNode = curNode->next[edgeValue];
            }
            else{
                trieNode *newNode = new trieNode();
                curNode->next[edgeValue] = newNode;
                curNode = newNode;
            }
        }
        curNode->cntWord += 1;
    }

    int countSubsequence(trieNode *curNode, int lastPos){
        if(curNode == NULL) return 0;

        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(curNode->next[i] == NULL) cnt += countSubsequence(curNode->next[i], lastPos);
            else{
                auto lo = lower_bound(position[i].begin(), position[i].end(), lastPos);
                int loIndex = lo - position[i].begin();
                if(lo == position[i].end() || lastPos > position[i][loIndex]) continue;

                cnt += countSubsequence(curNode->next[i], position[i][loIndex] + 1);
            }
        }
        return curNode->cntWord + cnt;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i = 0; s[i]; i++){
            char ch = s[i];
            position[ch-'a'].push_back(i);
        }

        rootNode = new trieNode();
        for(string &word : words) insertWord(word);
        int totalSubsequence = countSubsequence(rootNode, -1);
        return totalSubsequence;
    }
};
