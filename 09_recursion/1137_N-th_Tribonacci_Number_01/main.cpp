class Solution {
public:
    int tribonacci(int n) {
        memo.resize(n + 1, -1);
        return helper(n);
    }
private:
    int helper(int n) {
        //base case 
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(memo[n] != -1) return memo[n];
        memo[n] = helper(n-1) +helper(n-2) + helper(n-3);
        return memo[n];
    }    
    vector<int> memo;
};