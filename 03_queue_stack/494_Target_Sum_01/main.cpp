class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return path(nums, S, 0);
    }
    
    int path(vector<int>& nums, uint target, int left) {
        if(target == 0 && left == nums.size()) return 1;
        if(left >= nums.size()) return 0;
        int ans = 0;
        ans += path(nums, target + nums[left], left + 1);
        ans += path(nums, target - nums[left], left + 1);
        return ans;
    }
};

