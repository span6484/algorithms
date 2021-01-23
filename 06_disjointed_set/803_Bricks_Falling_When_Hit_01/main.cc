class UnionFind {
public:
    UnionFind(int n) : parent(n), size(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            x = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return;
        if(size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
    int getSize(int x) {
        int rootx = find(x);
        return size[rootx];
    }
private:
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        int top = m*n;
        int l = hits.size();
        vector<int> res(l);
        vector<vector<int> > copy(grid);
        for(const auto& h : hits) {
            copy[h[0]][h[1]] = 0;
        }

        UnionFind uf(top+1);
        // union top
        for(int j = 0; j < n; j++) {
            if(copy[0][j] == 0) continue;
            uf.merge(j, top);    
        }
        // union other 
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(copy[i][j] == 0) continue;
                if(copy[i-1][j] == 1) {
                    uf.merge(i*n+j, (i-1)*n+j);
                }
                if(j > 0 && copy[i][j-1] == 1) {
                    uf.merge(i*n+j, i*n+j-1);
                }
            }
        }
        vector<vector<int> > dir = {{-1,0}, {0,-1}, {0, 1}, {1, 0}};
        // reversely add hits
        for(int k = hits.size() - 1; k >= 0; k--) {
            int i = hits[k][0];
            int j = hits[k][1];
            if(grid[i][j] == 0) continue;
            int oldSize = uf.getSize(top);
            // add top
            if(i == 0) {
                uf.merge(j, top);
            } 
            copy[i][j] = 1;
            for(const auto& d : dir) {
                int r = i + d[0];
                int c = j + d[1];
                if(r < 0 || r >= m || c < 0 || c >= n || 
                    copy[r][c] == 0) continue;
                uf.merge(i * n + j, r * n + c);
            }
            int newSize = uf.getSize(top);
            res[k] = max(0, newSize - oldSize - 1);
        }
        return res;

    }
};