class Leaderboard {
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        if(m.find(playerId) != m.end()) {
            m.at(playerId) += score;
        } else {
            m.insert({playerId, score});
        }
    }   
    
    int top(int K) {
        priority_queue<int> q;
        for(auto it = m.begin(); it != m.end(); it++) {
            q.push(it->second);
        }
        int sum = 0;
        while(!q.empty() && K > 0) {
            int s = q.top(); q.pop();
            sum += s;
            K--;
        }
        return  sum;
    }
    
    void reset(int playerId) {
        m.erase(playerId);
    }
private:    
    map<int, int> m;
};