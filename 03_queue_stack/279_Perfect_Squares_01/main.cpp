class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        unordered_map<int,int> visited;
        visited[n] = 1;
        int step = 0;
        while(!q.empty()) {
            int size = q.size();
            step++;
            for(int j = 0; j < size; j++) {
                n = q.front();
                q.pop();
                for(int i = 1; n - i*i >= 0; i++) {
                    int tmp = n - i*i;
                    if(tmp == 0) return step;
                    if(visited[tmp] != 1) {
                        visited[tmp] = 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return step;
    }
};