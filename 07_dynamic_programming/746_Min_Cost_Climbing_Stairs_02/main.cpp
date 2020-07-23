class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 0) return 0;
        cost.push_back(0);
        int len = cost.size();
        store.resize(len);
        for(int i = 0; i < len; i++) {
            store[i] = -1;
        }
        return path(cost, len-1);
    }
    int path(vector<int>& cost, int idx) {
        if(idx == 0 || idx == 1) return cost[idx];
        if(store[idx] != -1) return store[idx];
        store[idx] = min(path(cost, idx - 2), path(cost, idx - 1)) + cost[idx];
        return store[idx];
    }
private:
    vector<int> store;
};