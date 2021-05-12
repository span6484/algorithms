class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        bool res = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    res = dfs(i, j, 0, board, word);
                    if(res) return res;                 
                }
            }
        }
        return false;
    }
private:
    bool dfs(int i, int j, int cur, vector<vector<char>>& board, const string& word) {
        if(cur == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        char c = board[i][j];
        if(board[i][j] == '0' || board[i][j] != word[cur]) {
            return false;
        } 
        board[i][j] = '0';
        if(dfs(i-1, j, cur+1, board,word) ||
            dfs(i+1, j, cur+1, board,word) ||
            dfs(i, j-1, cur+1, board, word) ||
            dfs(i, j+1, cur+1, board, word))
            return true;
        board[i][j] = c;
        return false;
    }
};