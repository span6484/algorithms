/*
 * @Author: Shiyu Yi
 * @Github: https://github.com/chanchann
 */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> res;
        sort(envelopes.begin(), envelopes.end(),
        [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0]? a[1] > b[1] : a[0] < b[0];
        });
        for(const auto& e : envelopes) {
            auto it = lower_bound(res.begin(), res.end(), e[1]);
            if(it == res.end()) res.push_back(e[1]);
            else *it = e[1];
        }
        return res.size();
    }
};