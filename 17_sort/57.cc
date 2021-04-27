class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        if(intervals.empty()) return {newInterval};
        bool replaced = false;
        int left = newInterval[0];
        int right = newInterval[1];
        for(auto &interval : intervals) {
            // 在左侧无交集
            if(interval[0] > right) {
                if(!replaced) {
                    res.push_back({left, right});
                    replaced = true;
                }
                res.push_back(interval);
            } else if(interval[1] < left) {  // 在右侧，无交集
                res.push_back(interval);
            } else {   // 有交集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if(!replaced) res.push_back({left, right});
        return res;
    }
};