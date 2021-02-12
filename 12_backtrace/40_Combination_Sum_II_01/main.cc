class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 去重操作
        candi_ = candidates;
        backtrace(0, target);
        return res;
    }

    void backtrace(int idx, int remain) {
        if(!remain) {
            res.push_back(state);
            return;
        } else if(remain < 0) {
            return;
        }
        for(int i = idx; i < candi_.size(); i++) {
            if(i > idx && candi_[i] == candi_[i-1]) continue;  // 去重操作
            state.push_back(candi_[i]);
            backtrace(i+1, remain-candi_[i]);
            state.pop_back();
        }
    }
private:
    vector<vector<int> > res;
    vector<int> state;
    vector<int> candi_;
};