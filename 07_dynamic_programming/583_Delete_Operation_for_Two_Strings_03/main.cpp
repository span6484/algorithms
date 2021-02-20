class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        auto memo = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(word1[i-1] == word2[j-1]) memo[i][j] = memo[i-1][j-1] + 1;
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return l1+l2-memo[l1][l2]*2;
    }
};