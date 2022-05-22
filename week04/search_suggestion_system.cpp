/**
Time: O(3 * L * N), L = max length in products, N = size of s.
Memory: O(S), S = total number of characters in all strings in products.
**/

class Solution {
public:
    class TrieNode
    {
      public:
        bool isWord;
        TrieNode* next[26];
        TrieNode()
        {
            isWord = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrie(vector<string>&products)
    {
        TrieNode* root = new TrieNode();
        for (auto &wd : products)
        {
            TrieNode* curr = root;
            for (auto &c : wd)
            {
                int id = c - 'a';
                if (curr -> next[id] == NULL) curr -> next[id] = new TrieNode();
                curr = curr->next[id];
            }
            curr->isWord = true;
        }
        return root;
    }
    void dfs(TrieNode* u, string& curr, vector<string>&words)
    {
        if (u == NULL || words.size() == 3) return;
        if (u -> isWord && words.size() < 3)
        {
            words.push_back(curr);
        }
        for (int i = 0; i < 26; i++)
        {
            curr.push_back((char)(i + 'a'));
            dfs(u -> next[i], curr, words);
            curr.pop_back();
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = generateTrie(products);
        vector<vector<string>> suggestions;
        string curr = "";
        for (auto c : searchWord)
        {
            root = root && root->next[c - 'a'] ? root->next[c - 'a'] : NULL;
            vector<string>words;
            curr.push_back(c);
            dfs(root, curr, words);
            suggestions.push_back(words);
        }
        return suggestions;
    }
};