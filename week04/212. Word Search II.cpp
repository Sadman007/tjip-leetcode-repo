//TC: O(N * M * K)  -> N := row, M := colum, K := 4 * 3^|word|
//MC: O(n)          -> n := Σ|word[i]| * 26

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
    vector<int> dir{-1, 0, 1, 0, -1}; // consecutive 2ta nile current cell theke adjacent cell a move kora jay

    trieNode *generateTrie(vector<string> &words){
        trieNode *rootNode = new trieNode();
        for(string &word : words){
            trieNode *curNode = rootNode;
            for(char &ch : word){
                int edgeValue = ch - 'a';
                if(curNode->next[edgeValue] == NULL) curNode->next[edgeValue] = new trieNode();
                curNode = curNode->next[edgeValue];
            }
            curNode->nodeWord = word;
        }
        return rootNode;
    }

    void getWord(int r, int c, trieNode *curNode, vector<vector<char>> &board, vector<string> &res){
        char ch = board[r][c];
        curNode = curNode->next[ch-'a'];
        if(curNode == NULL) return;
        board[r][c] = '#';

        if(curNode->nodeWord.size()){
            res.push_back(curNode->nodeWord);
            curNode->nodeWord.clear();
        }

        for(int i = 0; i < 4; i++){
            int x = r + dir[i];
            int y = c + dir[i+1];
            bool isValid = x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '#';
            if(isValid){
                getWord(x, y, curNode, board, res);
            }
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trieNode *rootNode = generateTrie(words);
        int row = board.size(), col = board[0].size();

        vector<string> res;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                getWord(r, c, rootNode, board, res);
            }
        }
        return res;
    }
};
