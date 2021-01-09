class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        int res = 1;
        vector<int> memo(len, 1);
        for(int i = 1; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    memo[i] = max(memo[i], memo[j]+1);
            }
            res = max(res, memo[i]);
            if(res == 3) return true;
        }
        return false;
    }
};