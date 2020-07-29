class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        store.resize(amount + 1, -1);
        int res = dp(coins, amount);
        return res == INT_MAX ? -1 : res;
    }

    int dp(vector<int>& coins, int amount) {
        int res = INT_MAX;
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(store[amount] != -1) return store[amount];
        for(auto coin:coins) {
            int tmp = dp(coins, amount - coin);
            if(tmp == INT_MAX) tmp = INT_MAX - 1;
            res = min(res, tmp + 1);
        }
        store[amount] = res;
        return store[amount];
    }
private: 
    vector<int> store;
};