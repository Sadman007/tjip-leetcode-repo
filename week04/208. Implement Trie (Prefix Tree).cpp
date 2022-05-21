// TC = O(N)
// MC = O(S) where S is total alphabet of all string
class TrieNode{
public:
    bool isWord;
    TrieNode* next[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
            isWord = false;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string str) {
        TrieNode* currNode = root;
        for(auto c:str){
            int order = c - 'a';
            if(currNode->next[order]==NULL){
                currNode->next[order] = new TrieNode();
            }
            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }

    bool search(string str, bool isPrefixSearch = false) {
        TrieNode* currNode = root;
        for(auto c: str){
            int order = c - 'a';
            if(currNode->next[order]==NULL){
                return false;
            }
            currNode = currNode->next[order];
        }
        return currNode && (currNode->isWord || isPrefixSearch);
    }

    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

