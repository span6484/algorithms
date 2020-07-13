class Solution {
public:
    int solve(int idx, vector<int>& nums) {
        if(idx < 0) return 0;
        if(store[idx] != -1) return store[idx];
        store[idx] = max((nums[idx] + solve(idx - 2, nums)), 
        solve(idx-1, nums));
        return store[idx];
    }
    int rob(vector<int>& nums) {
        store.resize(nums.size(), -1);
        return solve(nums.size() - 1, nums);
    }
private:
    vector<int> store;
};