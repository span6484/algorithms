class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        vector<vector<int> > memo(2, vector<int>(len2 + 1, 0));
        for(int i = 1; i < len1 + 1; i++) {
            for(int j = 1; j < len2 + 1; j++) {
                if(A[i - 1] == B[j - 1]) {
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + 1;
                }else {
                    memo[i % 2][j] = max(memo[(i - 1) % 2][j], memo[i % 2][j - 1]);
                }
            }
        } 
        return memo[len1 % 2][len2];
    }
};