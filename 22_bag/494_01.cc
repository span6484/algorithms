class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        sum += target;
        if(sum % 2) return 0;
        sum /= 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(auto & num : nums) {
            for(int i = sum; i >= num; i--) {
                dp[i] = dp[i] + dp[i-num];
            }
        }
        return dp[sum];
    }
};