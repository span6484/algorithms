class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int len = cost.size();
        vector<int> store(len);
        store[0] = cost[0];
        store[1] = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            store[i] = min(store[i - 2], store[i - 1]) + cost[i];
        }
        return store[len-1];
    }
};