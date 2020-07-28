class Solution {
public:
    int search(int idx, int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(idx < 0) return INT_MAX;
        if(store[idx][amount] != -1) return store[idx][amount];
        int tmp = search(idx, amount-coins[idx], coins);
        if(tmp == INT_MAX) tmp = INT_MAX - 1;
        store[idx][amount] = min(tmp + 1, search(idx-1, amount, coins));
        return store[idx][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if(len <= 0) return -1;
        store.resize(len);
        for (int i = 0; i < len; i++){
            store[i].resize(amount+1, -1);
        }
        int res = search(coins.size() - 1, amount, coins);
        return res == INT_MAX ? -1 : res;
    }
private:
    vector<vector<int> > store;
};