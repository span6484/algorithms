class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        for(int num : nums) {
            cnt[num]++;
        }
        int sz = nums.size();
        vector<vector<int> > res;
        for(int i = 0; i < sz-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < sz-1; j++) {
                if(j-1 != i && nums[j] == nums[j-1]) continue;
                int thir = 0 - nums[i] - nums[j];
                if(thir < nums[j] || !cnt.count(thir)) continue;
                if(cnt[thir] >= 1 + (nums[i] == thir) + (nums[j] == thir)) {
                    // cout << i << " " << j << endl;
                    res.push_back({nums[i], nums[j], thir});
                }
            }
        }
        return res;  
    }
};