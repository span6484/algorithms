class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, 0, cur, true);
        return res_;
    }
private:
    void dfs(vector<int>& nums, int i, vector<int> cur, bool add) { 
        if(add) res_.push_back(cur);
        if(i >= nums.size()) return;
        dfs(nums, i+1, cur, false);
        cur.push_back(nums[i]);
        dfs(nums, i+1, cur, true);
    }
private:
    vector<vector<int> > res_;
};