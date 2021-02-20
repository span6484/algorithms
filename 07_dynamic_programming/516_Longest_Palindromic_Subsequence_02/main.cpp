class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string w(s.rbegin(), s.rend());
        int l1 = s.size(), l2 = l1;
        vector<vector<int> > memo = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(s[i-1] == w[j-1]) memo[i][j] = memo[i-1][j-1] + 1;  
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[l1][l2];
    }

};
/*

递归可能无法通过
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string reversed(s.rbegin(), s.rend());
        int i = s.size(), j = i;
        memo = vector<vector<int> >(i+1, vector<int>(j+1, 0));
        return dp(s, w, i, j);
    }
    int dp(const string& a, const string& b, int i, int j) {
        if(!i || !j || memo[i][j] > 0) return memo[i][j];
        if(a[i-1] == b[j-1]) memo[i][j] = dp(a, b, i-1, j-1) + 1;
        else memo[i][j] = max(dp(a, b, i-1,j), dp(a, b, i, j-1));
        return memo[i][j];
    }
private:
    vector<vector<int> > memo;
};



*/