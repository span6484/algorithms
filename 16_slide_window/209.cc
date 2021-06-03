class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = INT_MAX;
        int sz = nums.size();
        int sum = 0;
        while(r < sz) {
            sum += nums[r];
            r++;
            while(sum >= target) {
                int len = r - l;
                res = min(res, len);
                sum -= nums[l];
                l++;
            }
        }
        return res == INT_MAX ? 0 : res;

    }
};