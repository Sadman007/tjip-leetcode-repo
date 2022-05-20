// TC = O(NM * 4*3^(word_length)) where N = size of words and M = size of each words[i]
// MC = O(S) where S is the total char of all word[i] in words
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

    TrieNode* generateTrie(vector<string> &words){
        TrieNode* root = new TrieNode();

        for(auto &s:words){
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

    vector<int> dir{-1, 0, 1, 0, -1};

    bool isValid(int x, int y, vector<vector<char>>& board){
        return (x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]!='#');
    }

    // O(4*3^(word_length)
    void dfs(int x, int y, vector<vector<char>>& board, TrieNode* currNode, vector<string> &wordsOnBoard){

        char c = board[x][y];
        if(c=='#' || (currNode && currNode->next[c-'a']==NULL)) return;
        currNode = currNode->next[c - 'a'];

        if(currNode && currNode->word.size()>0){
            wordsOnBoard.push_back(currNode->word);
            currNode->word.clear();
        }
        board[x][y] = '#';
        for(int i = 0; i < 4; i++){
            int X = x + dir[i];
            int Y = y + dir[i+1];
            if(isValid(X,Y,board)){
                dfs(X, Y, board, currNode, wordsOnBoard);
            }
        }
        board[x][y] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = generateTrie(words);
        int n = board.size();
        int m = board[0].size();
        vector<string> wordsOnBoard;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, board, root, wordsOnBoard);
            }
        }
        return wordsOnBoard;
    }
};
