class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        memo.resize(n+1);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i <= n; i++) {
            memo[i] = (memo[i-1] + memo[i-2]) % 1000000007;
        }
        return memo[n];
    }
private:
    vector<int> memo;
};