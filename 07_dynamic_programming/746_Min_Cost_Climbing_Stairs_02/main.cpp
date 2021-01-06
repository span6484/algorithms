class Solution {
public:
    int dp(int idx, vector<int>& cost) {
        if(idx == 0 || idx == 1) return cost[idx];
        if(memo[idx] != -1) return memo[idx];
        memo[idx] = cost[idx] + min(dp(idx-1, cost), dp(idx-2,cost)); 
        return memo[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        memo.resize(cost.size()+1, -1);
        return dp(cost.size()-1, cost);
    }
private:
    vector<int> memo;
};