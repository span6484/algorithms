class UF {
public:
    UF(int num) : parent(num), size(num) {
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
    bool merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return false;
        if(size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size()+1);
        for(const auto& e : edges) {
            if(!uf.merge(e[0], e[1]))
                return e;
        }
        return {}; 
    }
};