class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> memo(nums);
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            memo[i] = memo[i-1] > 0 ? memo[i-1]+nums[i] : nums[i];
            max = std::max(memo[i], max);
        }
        return max;
    }
};