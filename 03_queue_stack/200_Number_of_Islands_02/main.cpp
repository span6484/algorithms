class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        queue<pair<int, int> > que;
        int res = 0;
        for(int i =0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    que.push({i, j});
                    grid[i][j] = '0';
                    res++;
                    while(!que.empty()) {
                        int r = que.front().first;
                        int c = que.front().second;
                        que.pop();
                        if(r > 0 && grid[r-1][c] == '1') {
                            grid[r-1][c] = '0';
                            que.push({r-1,c});
                        }
                        if(r+1 < grid.size() && grid[r+1][c] == '1') {
                            grid[r+1][c] = '0';
                            que.push({r+1,c});
                        }
                        if(c > 0 && grid[r][c-1] == '1') {
                            grid[r][c-1] = '0';
                            que.push({r,c-1});
                        }
                        if(c+1 < grid[0].size() && grid[r][c+1] == '1') {
                            grid[r][c+1] = '0';
                            que.push({r,c+1});
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};