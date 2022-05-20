// TC = O(min(3*M, S)) where M = avg length of each string and S is the sum of all char in products..3*M = dfs() time..S = Trie construct time
// MC = O(S)
class Solution {
public:
    class TrieNode{
    public:
        string word;
        TrieNode* next[26];
        TrieNode(){
            word = "";
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrie(vector<string> &products){
        TrieNode* root = new TrieNode();

        for(auto &s:products){
            TrieNode* currNode = root;
            for(auto &c:s){// insertString()
                int id = c - 'a';
                if(currNode->next[id]==NULL){
                    currNode->next[id] = new TrieNode();
                }
                currNode = currNode->next[id];
            }
            currNode->word = s;// word rakhar jnno highest 2*10^4 ta memory khoroch hbe
        }
        return root;
    }

    void dfs(TrieNode* u, vector<string> &words){
        if(u==NULL || words.size()==3) return;
        if(u->word.size()>0 && words.size()<3){
            words.push_back(u->word);
        }
        for(int i = 0; i < 26; i++){
            dfs(u->next[i], words);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = generateTrie(products);
        vector<vector<string> > suggestions;
        for(auto &c: searchWord){
            // root=NULL mane c='k' hoy ja trie te nai and root->next[c-'a'] NULL kina check korbo..jodi ektao NULL hoy tahole NULL return korbo..else root take ek ghor niche namabo
            root = root && root->next[c - 'a']? root->next[c-'a'] : NULL;
            vector<string> words;
            dfs(root, words);
            suggestions.push_back(words);
        }
        return suggestions;
    }
};

/***********************************************************************/
// TC = O(min(3*M, S)) where M = avg length of each string and S is the sum of all char in products..3*M = dfs() time..S = Trie construct time
// MC = O(S)
class Solution {
public:
    class TrieNode{
    public:
        bool isWord;
        TrieNode* next[26];
        TrieNode(){
            isWord = false;
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrie(vector<string> &products){
        TrieNode* root = new TrieNode();

        for(auto &s:products){
            TrieNode* currNode = root;
            for(auto &c:s){// insertString()
                int id = c - 'a';
                if(currNode->next[id]==NULL){
                    currNode->next[id] = new TrieNode();
                }
                currNode = currNode->next[id];
            }
            currNode->isWord = true;
        }
        return root;
    }

    void dfs(TrieNode* u, string &curr, vector<string> &words){
        // curr a highest 3000 length er ekta string toiri hbe
        if(u==NULL || words.size()==3) return;
        if(u->isWord && words.size()<3){
            words.push_back(curr);
        }
        for(int i = 0; i < 26; i++){
            curr.push_back((char)(i + 'a'));
            dfs(u->next[i], curr, words);
            curr.pop_back();
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = generateTrie(products);
        vector<vector<string> > suggestions;
        string curr = "";
        for(auto &c: searchWord){
            // root=NULL mane c='k' hoy ja trie te nai and root->next[c-'a'] NULL kina check korbo..
            // jodi ektao NULL hoy tahole NULL return korbo..else root take ek ghor niche namabo
            root = root && root->next[c - 'a']? root->next[c-'a'] : NULL;
            vector<string> words;
            curr.push_back(c);
            dfs(root, curr, words);
            suggestions.push_back(words);
        }
        return suggestions;
    }
};
