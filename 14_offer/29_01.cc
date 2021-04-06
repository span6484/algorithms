class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int l = 0;
        int r = matrix[0].size()-1;
        int t = 0;
        int b = matrix.size()-1;
        while(true) {
            // left -> right
            for(int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if(b < ++t) break;
            // top -> bottom
            for(int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if(l > --r) break;
            // right -> left
            for(int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if(--b < t) break;
            // bottom -> top
            for(int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return res;
    }
};