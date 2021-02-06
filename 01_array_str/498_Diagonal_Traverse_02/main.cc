class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return {};
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0;
        vector<int> res(m * n);
        for(int k = 0; k < m*n; k++) {
            res[k] = matrix[i][j];
            if((i+j) % 2) {  // 奇数
                if(i == m-1) { // 在最后一行
                    j++;
                } else if(j == 0) {  // 第一列
                    i++;
                } else {
                    i++;
                    j--;
                }
            } else {    // 偶数
                if(j == n-1) {  // 在最后一列
                    i++;
                } else if(i == 0) {  // 在第一行
                    j++;
                } else {
                    i--;
                    j++;
                }
            }   
        }
        return res;
    }
};