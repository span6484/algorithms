class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> memo(cost.size(), -1);
        memo[0] = cost[0];
        memo[1] = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            memo[i] = cost[i] + min(memo[i-1], memo[i-2]);
        }
        return memo[cost.size()-1];
    }
};