class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo;
        for(auto num : nums) {
            auto it = lower_bound(memo.begin(), memo.end(), num);
            if(it == memo.end()) memo.push_back(num);
            else *it = num;
        }
        return memo.size();
    }
};