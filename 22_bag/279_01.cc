class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= sqrt(n); i++) {
            for(int j = 1; j <= n; j++) {
                if(j - i*i >= 0) 
                    dp[j] = min(dp[j], dp[j - i*i] +1);
            }
        }
        return dp[n];
    }
};