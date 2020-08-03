class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        memo.resize(len1);
        for (int i = 0; i < len1; i++){
            memo[i].resize(len2, -1);
        }
        return dp(A, B, len1 - 1, len2 - 1);
    }

    int dp(vector<int>& A, vector<int>& B, int i, int j) {
        if(i == -1 || j == -1) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(A[i] == B[j]) {
            memo[i][j] = dp(A, B, i-1, j-1) + 1;
        }else {
            memo[i][j] = max(dp(A, B, i, j-1), dp(A, B, i-1, j));
        }
        return memo[i][j];
    }
private:
    vector<vector<int> > memo;
};