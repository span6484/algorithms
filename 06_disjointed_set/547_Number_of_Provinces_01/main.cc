class UF {
public:
    UF(int num) : parent(num), size(num), count(num) {
        for(int i = 0; i < num; i++) {
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
        count--;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int getCount() const {
        return count;
    }
private:
    vector<int> parent;
    vector<int> size;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.getCount();
    }
};