//TC: O(N)  -> N := Σ|words[i]| * 26
//MC: O(N)

class Trie {
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

    trieNode *rootNode;

    Trie() {
        rootNode = new trieNode();
    }

    void insert(string word){
        trieNode *curNode = rootNode;
        for(char &ch : word){
            int edgeValue = ch - 'a';
            if(curNode->next[edgeValue] != NULL){  //path exist
                curNode = curNode->next[edgeValue];
            }
            else{
                trieNode *newNode = new trieNode();
                curNode->next[edgeValue] = newNode;
                curNode = newNode;
            }
        }
        curNode->isWord = true;
    }

    bool search(string word, bool isPrefix = 0){
        trieNode *curNode = rootNode;
        for(char &ch : word){
            int edgeValue = ch - 'a';
            if(curNode->next[edgeValue] == NULL) return false;
            curNode = curNode->next[edgeValue];
        }
        return curNode->isWord || isPrefix;
    }

    bool startsWith(string word){
        return search(word, 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
