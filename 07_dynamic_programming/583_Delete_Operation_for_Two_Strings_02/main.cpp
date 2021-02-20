class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();   
        memo = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));
        return l1 + l2 - dp(word1, word2, l1, l2)*2;
    }

    int dp(const string& word1, const string& word2, int l1, int l2) {
        if(!l1 || !l2 || memo[l1][l2] > 0) return memo[l1][l2];
        if(word1[l1-1] == word2[l2-1]) memo[l1][l2] = dp(word1, word2, l1-1, l2-1) + 1;
        else memo[l1][l2] = max(dp(word1, word2, l1-1, l2), dp(word1, word2, l1, l2-1));
        return memo[l1][l2];
    } 

    vector<vector<int> > memo;

};