class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        num = nums;
        backtrace(0);
        return res;
    }
    void backtrace(int idx) {
        res.push_back(state);
        for(int i = idx; i < num.size(); i++) {
            if(i > idx && num[i] == num[i-1]) continue;
            state.push_back(num[i]);
            backtrace(i+1);
            state.pop_back();
        }
    }

private:
    vector<vector<int> > res;
    vector<int> state;
    vector<int> num;
};