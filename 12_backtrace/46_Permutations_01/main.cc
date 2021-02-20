class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        state = nums;
        backtrace(0, nums.size());
        return res;
    }
    void backtrace(int idx, int cnt) {
        if(!cnt) {
            res.push_back(state);
        }
        for(int i = idx; i < state.size(); i++) {
            swap(state[i], state[idx]);
            backtrace(idx+1, cnt-1);
            swap(state[i], state[idx]);
        }
    }
private:
    vector<vector<int> > res;
    vector<int> state;
};