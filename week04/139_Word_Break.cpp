//TC: O(N)  -> N := |s| * 20 * 20
//MC: O(M)    -> M := Σ|words[i]| * 26 + 305

class Solution {
public:
    class trieNode{
    public:
        bool isWord;
        trieNode *next[26];

        trieNode(){
            isWord = false;
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };

    int dp[305], vis[305];

    trieNode *generateTrie(vector<string> &wordDict){
        trieNode *rootNode = new trieNode();
        for(string &word : wordDict) {
            trieNode *curNode = rootNode;
            for(char &ch : word){
                int edgeValue = ch - 'a';
                if(curNode->next[edgeValue] == NULL) curNode->next[edgeValue] = new trieNode();
                curNode = curNode->next[edgeValue];
            }
            curNode->isWord = true;
        }
        return rootNode;
    }

    bool checkTrie(int pos, int len, string &s, trieNode *rootNode){
        trieNode *curNode = rootNode;
        for(int i = pos, j = 1; j <= len; i++, j++){
            int edgeValue = s[i] - 'a';
            if(curNode->next[edgeValue] == NULL) return false;
            curNode = curNode->next[edgeValue];
        }
        return curNode->isWord;
    }

    bool getResult(int pos, string &s, trieNode *rootNode){
        if(pos >= s.size()) return true;
        if(vis[pos]) return dp[pos];
        bool curResult = 0;
        for(int i = pos, len = 1; s[i] && len <= 20; i++, len++){
            curResult |= (checkTrie(pos, len, s, rootNode) & getResult(pos+len, s, rootNode));
        }
        vis[pos] = 1;
        return dp[pos] = curResult;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        trieNode *rootNode = generateTrie(wordDict);

        return getResult(0, s, rootNode);
    }
};
