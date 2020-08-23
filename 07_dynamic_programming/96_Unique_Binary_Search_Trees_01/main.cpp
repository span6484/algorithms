class Solution {
public:
    int numTrees(int n) {
        memo.resize(n + 1, 0);
        memo[0] = 1;
        return helper(n);
    }
private:
    vector<int> memo;
    
    int helper(int n) {
        if(memo[n] != 0) return memo[n];
        for(int i = 1; i <= n; i++) {
            memo[n] += helper(i - 1) * helper(n - i);
        }
        return memo[n];
    }
};