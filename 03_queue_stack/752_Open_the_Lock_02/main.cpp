class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> que;
        string init = "0000";
        if(visited.find(init) != visited.end()) return -1;
        que.push(init);
        visited.insert(init);
        int step = 0;
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                auto tmp = que.front(); que.pop();
                if(tmp == target)  return step;
                for(int i = 0; i < 4; i++) {
                    string a = tmp;
                    string b = tmp;
                    a[i] = a[i] == '9' ? '0' : a[i] + 1;
                    b[i] = b[i] == '0' ? '9' : b[i] - 1;
                    if(visited.find(a) == visited.end()) {
                        que.push(a);
                        visited.insert(a);
                    }
                    if(visited.find(b) == visited.end()) {
                        que.push(b);
                        visited.insert(b);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};