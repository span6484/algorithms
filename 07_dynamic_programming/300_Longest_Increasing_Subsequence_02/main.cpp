class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        std::vector<int> memo;
        memo.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > memo.back()) 
                memo.push_back(nums[i]);
            else {
                auto it = lower_bound(memo.begin(), memo.end(), nums[i]);
                *it = nums[i];
            }
        }
        return memo.size();
    }
};