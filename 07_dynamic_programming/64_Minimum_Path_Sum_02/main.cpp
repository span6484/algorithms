class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return path(grid, m-1, n-1);
    }
    int path(vector<vector<int>>& grid, int m, int n) {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n <0) {
            return INT_MAX;
        }
        return min(path(grid, m-1, n), path(grid, m, n-1)) + grid[m][n];
    }
};