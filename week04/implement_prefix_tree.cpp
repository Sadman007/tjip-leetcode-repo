/**
Time: O(s) per query, where s = length of the query string.
Memory: O(S) maximum, where S = length of all query string
**/

class TrieNode
{
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* head;
    Trie()
    {
       head = new TrieNode();  
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* currNode = head;
        for(auto &c : word)
        {
            int order = c - 'a';
            if(currNode -> next[order] == NULL) {
                currNode -> next[order] = new TrieNode();
            }
            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word, bool isPrefixSearch = false)
    {
        TrieNode* currNode = head;
        for(auto &c : word)
        {
            int order = c - 'a';
            if(currNode -> next[order] == NULL) {
                return false;
            }
            currNode = currNode->next[order];
        }
        return currNode && (currNode->isWord || isPrefixSearch);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

