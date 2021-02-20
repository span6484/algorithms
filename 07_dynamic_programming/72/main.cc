class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        memo = vector<vector<int> >(l1+1, vector<int>(l2+1, -1));
        return dp(word1, word2, l1, l2);
    }

private:
    int dp(const string& word1, const string& word2, int l1, int l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(memo[l1][l2] >= 0) return memo[l1][l2];
        if(word1[l1 - 1] == word2[l2 - 1]) return dp(word1, word2, l1 - 1, l2 - 1);
        memo[l1][l2] = 1 + min( dp(word1, word2, l1 - 1, l2),
                                min(dp(word1, word2, l1, l2 - 1),
                                dp(word1, word2, l1 - 1, l2 - 1)));
        return memo[l1][l2];
    }
    vector<vector<int> > memo;
};