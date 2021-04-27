class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if(!intervals.size()) return res;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(res.empty() || res.back()[1] < left) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
};