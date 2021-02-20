class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        memo = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));
        return dp(text1, text2, l1, l2);
    }
private:
    int dp(const string& text1, const string& text2, int l1, int l2) {
        if(!l1 || !l2 || memo[l1][l2] > 0) return memo[l1][l2];
        if(text1[l1-1] == text2[l2-1]) {
            memo[l1][l2] = dp(text1, text2, l1-1, l2-1) + 1;
        } else {
            memo[l1][l2] = max(dp(text1, text2, l1-1, l2),
                                dp(text1, text2, l1, l2-1));
        }
        return memo[l1][l2];
    } 
    vector<vector<int> > memo;
};