class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> memo;
        for(auto& w : wall) {
            int n = w.size();
            int sum = 0;
            for(int i = 0; i < n - 1; i++) {
                sum += w[i];
                memo[sum]++;
            }
        }
        int maxCnt = 0;
        for(auto& [_, c] : memo) {
            maxCnt = max(maxCnt, c);
        }
        return wall.size() - maxCnt;
    }
};