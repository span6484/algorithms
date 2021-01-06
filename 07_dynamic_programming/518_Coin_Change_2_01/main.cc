class Solution {
public:
    int dp(int idx, int amount, vector<int>& coins) {
        if(idx < 0) return 0;
        if(amount < 0) return 0;
        if(amount == 0) {
            return 1;
        };
        if(memo[idx][amount] != -1) return memo[idx][amount];
        memo[idx][amount] = dp(idx-1, amount, coins) + dp(idx, amount-coins[idx], coins);
        return memo[idx][amount];
    }

    int change(int amount, vector<int>& coins) {
        if(!amount) return 1;
        memo.resize(coins.size(), vector<int>(amount+1, -1));
        return dp(coins.size()-1, amount, coins);
    }
private:
    vector<vector<int> > memo;
};