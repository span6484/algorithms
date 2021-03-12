class Solution {
public:
    int racecar(int target) {
        memo.resize(target+1, 0);
        return dp(target);
    }
private:
    int dp(int t) {
        if(memo[t] > 0) return memo[t];
        // n是刚好或超越的做小值
        int n = ceil(log2(t+1));
        // 1. 全加速刚好到达
        if((1 << n) == t+1) return memo[t] = n;
        // 2. 先过然后再退回的情况
        // (n*A)AAAR -- dp(left)
        // left 路程 = 2^n-1 - t
        memo[t] = n + 1 + dp((1<<n)-1-t);
        // 3. 提前一个先返回在继续走
        // 返回肯定要小于n-1,不然又回过原点了
        for(int m = 0; m < n-1; m++) {
            int cur = (1<<(n-1)) - (1 << m);
            memo[t] = min(memo[t], n-1+1+m+1+dp(t-cur));
        }
        return memo[t];
    }
private:
    vector<int> memo;
};