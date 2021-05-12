class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, vector<vector<int> >& res) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(cur);
            return;    
        }
        for(int i = idx; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, cur, res);
            cur.pop_back();
        }
    }
};