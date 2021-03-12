class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix[matrix.size()-1][matrix[0].size()-1];
        while(l < r) {
            int m = l + (r-l)/2;
            int total = 0;
            // nlogn find <= m
            for(auto& row : matrix) {
                total += upper_bound(row.begin(), row.end(), m) - row.begin();
            }
            if(total >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};