class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        for(int i = 0; i < memo.size(); i++) {
            for(int coin : coins) {
                if(i - coin < 0) continue;
                memo[i] = min(memo[i], memo[i - coin] + 1);
            }
        }
        return memo[amount] == amount+1 ? -1 : memo[amount];
    }
};