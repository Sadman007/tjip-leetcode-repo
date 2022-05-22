/**
Time: O(NM * 4^min(L, NM)) where N = # of rows, M = # of cols, L = max length of a string in words.
Memory: O(S), where S = total number of characters in words.
**/

class Solution {
public:
    class TrieNode
    {
      public:
        string word;
        TrieNode* next[26];
        TrieNode()
        {
            word = "";
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    vector<int> dir{-1, 0, 1, 0, -1};
    
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
            curr->word = wd;
        }
        return root;
    }
    void dfs(int x, int y, vector<vector<char>> &board, TrieNode* currNode, vector<string>&wordsOnBoard)
    {
        char ch = board[x][y];
        if (ch == '#' || (currNode && currNode -> next[ch - 'a'] == NULL)) return;
        currNode = currNode -> next[ch - 'a'];
        
        if (currNode && currNode->word.size() > 0)
        {
            wordsOnBoard.push_back(currNode->word);
            currNode->word.clear();
        }
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int X = x + dir[i];
            int Y = y + dir[i + 1];
            if (X < 0 || Y < 0 || X >= board.size() || Y >= board[0].size() || board[X][Y] == '#') continue;
            dfs(X, Y, board, currNode, wordsOnBoard);
        }
        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = generateTrie(words);
        vector<string> wordsOnBoard;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j, board, root, wordsOnBoard);
            }
        }
        return wordsOnBoard;
    }
};

