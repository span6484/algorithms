class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int> > memo(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i < len1 + 1; i++) {
            for(int j = 1 ; j < len2 + 1; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                } else {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }
        return memo[len1][len2];
    }
};