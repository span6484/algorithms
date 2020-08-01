class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        memo.resize(len1);
        for(int i= 0; i < len1; i++){
            memo[i].resize(len2, -1);
        }
        return dp(text1, text2, len1 - 1, len2 - 1);
    }

    int dp(string& text1, string& text2, int xi, int yi) {
        if(xi == -1 || yi == -1) return 0; 
        if(memo[xi][yi] != -1) return memo[xi][yi];
        if(text1[xi] == text2[yi]) {
            memo[xi][yi] = dp(text1, text2, xi-1, yi-1) + 1;
        }else {
            memo[xi][yi] = max(dp(text1, text2, xi, yi-1),
            dp(text1, text2, xi-1, yi));
        }
        return memo[xi][yi];
    }
private:
    vector<vector<int> > memo;
};