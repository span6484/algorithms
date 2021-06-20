class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(helper(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool helper(vector<vector<char>>& board, const string& word, int i, int j, int cur) {
        // base case 
        if(cur == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if(board[i][j] != word[cur]) return false;
        if(board[i][j] == '\0') return false;

        char tmp = board[i][j];
        board[i][j] = '\0';

        bool res =  helper(board, word, i-1, j, cur+1) || helper(board, word, i+1, j, cur+1)
            || helper(board, word, i, j-1, cur+1) || helper(board, word, i, j+1, cur+1);
        board[i][j] = tmp;
        
        return res;
    }
  
};