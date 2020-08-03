class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > memo(2, vector<int>(len2 + 1, 0));
        for(int i = 1; i < len1 + 1; i++) {
            for(int j = 1; j < len2 + 1; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + 1;
                }else {
                    memo[i % 2][j] = max(memo[(i - 1) % 2][j], memo[i % 2][j - 1]);
                }
            }
        }
        return len1 + len2 - memo[len1 % 2][len2] * 2;
    }
};