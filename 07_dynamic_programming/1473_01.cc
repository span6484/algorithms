class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = dfs(houses, cost, 0, target, 0);
        return res >= inf ? -1 : res;
    }
private:
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int lastCor) {
        // boundary
        if(i >= houses.size() || target < 0) {
            return target == 0 ? target : inf;
        }
        
        // already painted last year
        if(houses[i]) return dfs(houses, cost, i+1, target-(lastCor != houses[i]), houses[i]);
        // cache
        if(dp[i][target][lastCor]) return dp[i][target][lastCor]; 
        // travsrse all the color 
        auto res = inf;
        for(int clr = 1; clr <= cost[i].size(); clr++) {
            res = min(res, cost[i][clr-1] + 
                    dfs(houses, cost, i+1, target - (clr != lastCor), clr));
        }
        return dp[i][target][lastCor] = res;
    }
private:
    int dp[101][101][21] = {};
    int inf = 1e6 + 1;
};