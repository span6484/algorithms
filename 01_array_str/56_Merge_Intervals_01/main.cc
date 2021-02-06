class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > res;
        for(int i = 0;i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(!res.size() || res.back()[1] < left) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], right);
            } 
        }
        return res;
    }
};