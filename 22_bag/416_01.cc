class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2) {
            return false;
        } else {
            sum /= 2;
        }
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(auto num : nums) {
            for(int i = sum; i >= num; i--) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum];
    }
};