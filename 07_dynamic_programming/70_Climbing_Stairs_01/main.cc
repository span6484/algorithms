class Solution {
public:
    int dp(int i) {
        if(memo[i] != -1) return memo[i];
        memo[i] = dp(i-1) + dp(i-2);
        return memo[i];
    }
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        memo.resize(n+1, -1);
        memo[0] = 1;
        memo[1] = 1;
        return dp(n);
    }
private:
    vector<int> memo;
};