class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal;
        for(auto num : nums) {
            maxVal = max(num, maxVal);
        }
        vector<int> sums(maxVal+1, 0);
        for(auto num : nums) {
            sums[num] += num;
        }
        return rob(sums);
    }
private:
    int rob(vector<int>& sums) {
        int sz = sums.size();
        if(sz == 0) return 0;
        if(sz == 1) return sums[0];
        vector<int> dp(sz, 0);
        dp[0] = sums[0];
        dp[1] = max(sums[0], sums[1]);
        for(int i = 2; i < sz; i++) {
            dp[i] = max(dp[i-2] + sums[i], dp[i-1]);
        }
        return dp[sz-1];
        
    }
};