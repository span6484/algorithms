class Solution {
public:
    int minimumTmeRequired(vector<int>& jobs, int k) {
        if(jobs.size() == k) return *max_element(begin(jobs), end(jobs));
        k_ = k;
        workers_.resize(k, 0);
        sort(begin(jobs), end(jobs), greater<int>());
        for(int i = 0; i < jobs.size(); i+=k) {
            res_ += jobs[i];
        }
        return dfs(0, 0, jobs);
    }
private:
    int dfs(int i, int cur, vector<int>& jobs) {
        if(cur >= res_) return res_;
        if(i == jobs.size()) return res_ = cur;
        unordered_set<int> visited;
        for(int j = 0; j < k_; j++) {
            if(!visited.insert(workers_[j]).second) continue;
            workers_[j] += jobs[i];
            dfs(i+1, max(cur, workers_[j]), jobs);
            workers_[j] -= jobs[i];
        }
        return res_;
    }

private:
    int res_;
    int k_;
    vector<int> workers_;
};