class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if(len1 < len2) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<vector<int> > memo(2, vector<int>(len2 + 1, 0));
        for(int i = 1; i < len1 + 1; i++) {
            for(int j = 1 ; j < len2 + 1; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + 1;
                } else {
                    memo[i % 2][j] = max(memo[(i - 1) % 2][j], memo[i % 2][j - 1]);
                }
            }
        }
        return memo[len1 % 2][len2];
    }
};