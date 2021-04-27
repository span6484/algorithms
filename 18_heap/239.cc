class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int> > q;
        for(int i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        vector<int> res{q.top().first};
        for(int i = k; i < nums.size(); i++) {
            q.push({nums[i], i});
            while(q.top().second <= i-k) {
                q.pop();
            }
            res.emplace_back(q.top().first);
        }
        return res;
    }  
};