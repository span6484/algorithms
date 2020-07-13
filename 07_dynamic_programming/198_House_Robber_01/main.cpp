class Solution {
public:
    int solve(int idx, vector<int>& nums) {
        if(idx < 0) return 0;
        return max((nums[idx] + solve(idx - 2, nums)), 
        solve(idx-1, nums));
    }
    int rob(vector<int>& nums) {
        return solve(nums.size() - 1, nums);
    }
};