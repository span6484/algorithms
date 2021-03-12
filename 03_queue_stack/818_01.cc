class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int> > q{{{0,1}}};
        unordered_set<string> visited{{"0,1"}};
        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto cur = q.front(); q.pop();
                int pos = cur.first;
                int speed = cur.second;
                if(pos == target) return step;
                // accelerate
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                string key = to_string(newPos) + "," + to_string(newSpeed);
                if(!visited.count(key) && newPos > 0 && newPos < 2* target) {
                    q.push({newPos, newSpeed});
                    visited.insert(key);
                }
                // reverse 
                newPos = pos;
                newSpeed = speed > 0 ? -1 : 1;
                key = to_string(newPos) + "," + to_string(newSpeed);
                if(!visited.count(key) && newPos > 0 && newPos < 2* target) {
                    q.push({newPos, newSpeed});
                    visited.insert(key);
                }
            }
            step++;
        }
        return -1;
    }
};