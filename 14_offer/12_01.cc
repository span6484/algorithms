class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!word.size()) return true;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    memo.insert({i, j});
                    if(helper(i, j, 1, board, word)) 
                        return true;
                    memo.clear();
                }
            }
        }
        return false;
    }

private:
    bool helper(int i, int j, int k, vector<vector<char>>& board, const string& word) {
        if(k == word.size()) return true;
        if(i > 0 && memo.find({i-1,j}) == memo.end() && board[i-1][j] == word[k]) {
            memo.insert({i,j});
            if(helper(i-1, j, k+1, board, word)) return true;
            else memo.erase({i-1,j});
        } 
        if(i < board.size() -1 && memo.find({i+1,j}) == memo.end() && board[i+1][j] == word[k] ) {
            memo.insert({i,j});
            if(helper(i+1, j, k+1, board, word)) return true;
            else memo.erase({i+1, j});
        }
        if(j > 0 && memo.find({i,j-1}) == memo.end() && board[i][j-1] == word[k]) {
            memo.insert({i,j});
            if(helper(i, j-1, k+1, board, word)) return true;
            else memo.erase({i,j-1});
        }
        if(j < board[0].size()-1 && memo.find({i,j+1}) == memo.end() && board[i][j+1] == word[k]) {
            memo.insert({i,j});
            if(helper(i, j+1, k+1, board, word)) return true;
            else memo.erase({i, j+1});
        }
        return false;
    }
private:
    set<pair<int, int> > memo;
};