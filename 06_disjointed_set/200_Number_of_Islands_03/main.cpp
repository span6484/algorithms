class UF {
public:
    UF(vector<vector<char>>& grid)  {
        int m = grid.size();
        int n = grid[0].size();
        parent.reserve(m*n);
        size.reserve(m*n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    parent[i*n+j] = i*n+j;
                    size[i*n+j] = 1; 
                    cnt++;
                }
            }
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            x = find(parent[x]);
        }
        return parent[x];
    }
    bool merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return false;
        if(size[rootx] <= size[rooty]) {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        } else {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        }
        cnt--;
        return true;
    }
    int count() {
        return cnt;
    }
private:
    vector<int> parent;
    vector<int> size;
    int cnt = 0;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UF uf(grid);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                 if(grid[i][j] == '1') {
                     if(j+1 < n && grid[i][j+1] == '1') uf.merge(i*n+j, i*n+j+1);
                     if(i+1 < m && grid[i+1][j] == '1') uf.merge(i*n+j, (i+1)*n+j);
                 }
            }
        }
        return uf.count();
    }
};