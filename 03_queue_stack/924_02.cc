class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int infectNum = INT_MAX, idx = 0;
        unordered_set<int> infected(initial.begin(), initial.end());
        for(auto init : initial) {  
            infected.erase(init);
            int cnt = 0;
            unordered_set<int> visited;    
            for(int num: infected) {
                dfs(graph, num, visited, cnt);
            }
            if(cnt < infectNum || (cnt == infectNum && init < idx)) {
                infectNum = cnt;
                idx = init;
                cout << infectNum << " " << idx << endl;
            }
            infected.insert(init);
        }
        return idx;
    }
private:
    void dfs(vector<vector<int>>& graph, int& num, unordered_set<int>& visited, int& cnt) {
        if(visited.count(num)) return;
        visited.insert(num);
        cnt++;

        for(int i = 0; i < graph[num].size(); i++) {
            if(graph[num][i] != 1) continue;
            dfs(graph, i, visited, cnt);
        }
    }
};