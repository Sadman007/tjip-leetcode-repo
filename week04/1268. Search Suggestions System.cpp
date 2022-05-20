//TC: O(M*N)  -> M := |searchWord|, N := Σ|words[i]| * 3
//MC: O(n)    -> n := Σ|words[i]| * 26
//MC calculation e confused

class Solution {
public:
    class trieNode{
    public:
        string nodeWord;
        trieNode *next[26];

        trieNode(){
            nodeWord = "";
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };
    trieNode *rootNode;
    void insertWord(trieNode *curNode, string &word){
        for(char &ch : word){
            int edgeValue = ch - 'a';
            if(curNode->next[edgeValue] == NULL) curNode->next[edgeValue] = new trieNode();
            curNode = curNode->next[edgeValue];
        }
        curNode->nodeWord = word;
    }

    void getSuggestedWords(trieNode *curNode, vector<string> &vec){
        if(curNode == NULL) return;
        if(curNode->nodeWord.size()) vec.push_back(curNode->nodeWord);

        for(int i = 0; i < 26; i++){
            if(vec.size() < 3) getSuggestedWords(curNode->next[i], vec);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        rootNode = new trieNode();
        for(string &word : products) insertWord(rootNode, word);

        vector<vector<string>> suggestedWords;
        trieNode *latestNode = rootNode;

        for(char &ch : searchWord){
            int edgeValue = ch - 'a';
            latestNode = latestNode && latestNode->next[edgeValue] ? latestNode->next[edgeValue] : NULL;
            vector<string> vec;
            getSuggestedWords(latestNode, vec);
            suggestedWords.push_back(vec);
        }
        return suggestedWords;
    }
};
