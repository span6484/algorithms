class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> memo;
        for(auto num : nums) {
            auto it = lower_bound(memo.begin(), memo.end(), num);
            if(it == memo.end()) memo.push_back(num);
            else *it = num;
            if(memo.size() == 3) return true;
        }
        return false;
    }
};