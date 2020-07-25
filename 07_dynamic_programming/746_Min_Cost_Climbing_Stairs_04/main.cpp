class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int len = cost.size();
        int fir = cost[0];
        int sec = cost[1];
        int tmp;
        for(int i = 2; i < len; i++) {
            tmp = min(fir, sec) + cost[i];
            fir = sec;
            sec = tmp;
        }
        return sec;
    }
};