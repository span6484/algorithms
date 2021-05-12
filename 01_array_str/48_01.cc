class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int j = 0; j < matrix[0].size(); j++) {
            for(int i = 0; i < matrix.size()/2; i++) {
                // 上下交换
                swap(matrix[i][j], matrix[matrix.size()-i-1][j]);
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < i; j++) {
                // 对角线
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};