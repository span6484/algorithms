class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        state = A;
        backtrace(0);
        return res;
    }
private:
    bool isSquare(int num) {
        int m = sqrt(num);
        if(m*m == num) return true;
        else return false;
    }
    void backtrace(int idx) {
        if(idx == state.size()) {
            res++;
            return;
        }
        unordered_set<int> memo;
        for(int i = idx; i < state.size(); i++) {
            if((idx > 0 && !isSquare(state[i] + state[idx-1])) || memo.find(state[i]) != memo.end()) continue;
            memo.insert(state[i]);
            swap(state[i], state[idx]);
            backtrace(idx+1);
            swap(state[i], state[idx]);
        }
    }
private:
    int res;
    vector<int> state;
};