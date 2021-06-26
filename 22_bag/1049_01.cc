class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sz = stones.size();
        int sum = 0;
        for(int i = 0; i < sz; i++) {
            sum += stones[i];
        }

        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(auto& stone : stones) {
            for(int i = target; i >= stone; i--) {
                dp[i] = dp[i] || dp[i-stone];
            }
        }
        int idx = 0;
        for(int j = target; j >= 0 ; j--) {
            if(dp[j]) {
                idx = j;
                break;
            }
        }
        return sum - 2 * idx;
        
    }
};