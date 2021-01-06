class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        vector<int> memo(n+1, 1);
        for(int i = 2; i <= n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};