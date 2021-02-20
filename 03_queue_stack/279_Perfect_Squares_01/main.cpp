class Solution {
public:
    int numSquares(int n) {
        queue<int> que;
        unordered_map<int, int> visited;
        que.push(n);
        visited[n] = 1;
        int step = 1;
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                int tmp = que.front(); que.pop();
                for(int i = 1; tmp - i*i >= 0; i++) {
                    int cur = tmp - i*i;
                    if(cur == 0) return step;
                    if(visited[cur] != 1) {
                        visited[cur] = 1;
                        que.push(cur);
                    }
                }
            }
            step++;
        }
        return step;
    }
};