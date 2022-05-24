/**
Time: O(N * S), S = total number of characters in words, N = length of string s
Memory: O(S)
**/

class Solution {
public:
    class TrieNode {
    public:
        char ch;
        int wordCount = 0;
        TrieNode* next[26];
        TrieNode(char c) {
            ch = c;
            wordCount = 0;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    TrieNode* createTrie(vector<string>&words) {
        TrieNode* root = new TrieNode('*'); // * means root.
        for (auto &word: words) {
            TrieNode* curr = root;
            for (auto &c : word) {
                if (curr -> next[c - 'a'] == NULL) {
                    curr -> next[c - 'a'] = new TrieNode(c);
                }
                curr = curr -> next[c - 'a'];
            }
            curr -> wordCount++;
        }
        return root;
    }
    
    int indexOf(string &s, char ch, int startFrom) {
        for (int i = startFrom; i < s.size(); i++) {
            if (s[i] == ch) return i;
        }
        return -1;
    }
    
    int dfs(string &s, TrieNode* u, int pos = 0) {
        if (u == NULL) return 0;
        int index = indexOf(s, u->ch, pos);
        if (u -> ch!='*' && index == -1) return 0;
        int res = u->wordCount;
        for (int i = 0; i < 26; i++) {
            res += dfs(s, u -> next[i], u->ch == '*'?  0 : index + 1);
        }
        return res;             
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        TrieNode* root = createTrie(words);
        return dfs(s, root);
    }
};
