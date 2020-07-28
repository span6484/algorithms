class Solution {
public:
    int search(int idx, int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(idx < 0) return INT_MAX;
        int tmp = search(idx, amount-coins[idx], coins);
        if(tmp == INT_MAX) tmp = INT_MAX - 1;
        return min(tmp + 1, search(idx-1, amount, coins));
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = search(coins.size() - 1, amount, coins);
        return res == INT_MAX ? -1 : res;
    }
};