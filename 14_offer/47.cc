class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > memo(row+1, vector<int>(col+1, 0));
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]) + grid[i-1][j-1];
            }
        } 
        return memo[row][col];
    }

};