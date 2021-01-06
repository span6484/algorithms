class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int fir = cost[0];
        int sec = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            int tmp = sec;
            sec = cost[i] + min(fir, sec);
            fir = tmp;
        }
        return sec;
    }
};