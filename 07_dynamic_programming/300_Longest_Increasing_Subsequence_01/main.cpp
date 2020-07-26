class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = numsx.size();
        if(!len) return 0;
        vector<int> dp(len, 1);
        int res;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};