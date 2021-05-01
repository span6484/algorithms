class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int idx = 0, res = INT_MAX;
        unordered_set<int> infected(initial.begin(), initial.end());
        for(auto init: initial) {
            infected.erase(init);
            int cnt = helper(graph, infected);
            if(cnt < res || (cnt == res && init < idx)) {
                res = cnt;
                idx = init;
            }
            infected.insert(init);
        }
        return idx;
    }
private:
    int helper(vector<vector<int>>& graph, unordered_set<int> infected) {
        queue<int> que;
        for(auto it = infected.begin(); it != infected.end(); it++) {
            que.push(*it);
        }
        while(!que.empty()) {
            int infec = que.front(); que.pop();
            for(int i = 0; i < graph[infec].size(); i++) {
                if(graph[infec][i] != 1 || infected.count(i)) continue;
                que.push(i);
                infected.insert(i);
            }
        }
        return infected.size();
    }
};