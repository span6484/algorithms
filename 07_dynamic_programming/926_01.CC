class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int sz = S.size();
        vector<int> l(sz+1, 0);
        vector<int> r(sz+1, 0);
        for(int i = 1; i <= sz; i++) {
            l[i] = l[i-1] + S[i-1] - '0'; 
        }
        for(int i = sz-1; i >= 0; i--) {
            r[i] = r[i+1] + '1' - S[i];
        }
        int res = INT_MAX;
        for(int i = 0; i <= sz; i++) {
            res = min(res, l[i] + r[i]);
        }
        return res;
    }
};