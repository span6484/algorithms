class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        store.resize(m);
        for (int i = 0; i < m; i++){
            store[i].resize(n, INT_MIN);
        }
        store[0][0] = grid[0][0];
        return path(grid, m-1, n-1);
    }
    int path(vector<vector<int>>& grid, int m, int n) {
        if(m < 0 || n < 0 ) {
            return INT_MAX;
        }
        if(store[m][n] != INT_MIN) return store[m][n];

        store[m][n] = min(path(grid, m-1, n), path(grid, m, n-1)) + grid[m][n];
        return store[m][n];
    }
private:
    vector<vector<int> > store;
};