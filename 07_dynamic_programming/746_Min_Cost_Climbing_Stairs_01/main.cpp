class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 0) return 0;
        cost.push_back(0);
        return path(cost, cost.size()-1);
    }
    int path(vector<int>& cost, int idx) {
        if(idx == 0 || idx == 1) return cost[idx];
        return min(path(cost, idx - 2), path(cost, idx - 1)) + cost[idx];
    }
};