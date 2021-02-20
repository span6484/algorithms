class Solution {
public:
    vector<string> permutation(string s) {
        state = s;
        backtrace(0);
        return res;
    }

    void backtrace(int idx) {
        if(idx >= state.size()) {
            res.push_back(state);
            return;
        }
        unordered_set<char> memo;
        for(int i = idx; i < state.size(); i++) {
            if(memo.find(state[i]) != memo.end()) continue;
            memo.insert(state[i]);
            swap(state[idx], state[i]);
            backtrace(idx+1);
            swap(state[idx], state[i]);
        }
    }
private:
    vector<string> res;
    string state;

};