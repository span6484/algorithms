class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto num : nums) {
            int idx = (num - 1) % n;
            nums[idx] += n;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= n) res.push_back(i+1);
        }
        return res;
    }
};