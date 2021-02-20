class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if(!sz) return sz;
        sort(envelopes.begin(), envelopes.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int res = 1;
        vector<int> memo(sz, 1);
        for(int i = 1; i < sz; i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[j][1] < envelopes[i][1]) {
                    memo[i] = max(memo[i], memo[j]+1);
                }
            }
            res = max(res, memo[i]);
        }
        return res;
    }
};