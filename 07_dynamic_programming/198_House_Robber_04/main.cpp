class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return nums[0];
        int fir = nums[0];
        int sec = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++) {
            int tmp = sec;
            sec = max((nums[i] + fir), sec);
            fir = tmp;
        }
        return sec;
    }
};