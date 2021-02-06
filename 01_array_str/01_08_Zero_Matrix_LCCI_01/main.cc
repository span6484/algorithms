class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size()) return;
        set<int> row;
        set<int> col;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(const auto& it : row) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[it][j] = 0;
            }
        }
        for(const auto& it : col) {
            cout << it << endl;
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][it] = 0;
            }
        }
    }
};