class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        memo.resize(n+1);
        memo[1] = 1;
        memo[2] = 2;
        for(int i = 3; i <= n; i++) {
            memo[i] = (memo[i-1] + memo[i-2]) % 1000000007;
        }
        return memo[n];
    }
private:
    vector<int> memo;
};