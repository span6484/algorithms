class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k == 0) return 1;
        int res = 0;
        queue<pair<int, int> > que;
        que.push({0,0});
        while(!que.empty()) {
            auto cur = que.front(); que.pop();
            int i = cur.first;
            int j = cur.second;
            if(i > 0 && isValid(i-1, j, k)) {
                res++;
                memo_.insert({i-1, j});
                que.push({i-1, j});
            }
            if(i < m-1 && isValid(i+1, j, k)) {
                res++;
                memo_.insert({i+1, j});
                que.push({i+1, j});
            }
            if(j > 0 && isValid(i, j-1, k)) {
                res++;
                memo_.insert({i, j-1});
                que.push({i, j-1});
            }
            if(j < n-1 && isValid(i, j+1, k)) {
                res++;
                memo_.insert({i, j+1});
                que.push({i, j+1});
            }
        }
        return res;
    }
private:
    bool isValid(int i, int j, int k) {
        if(memo_.find({i, j}) != memo_.end()) return false;
        int sum = 0;
        sum += addNum(i);
        sum += addNum(j);
        if(sum <= k) return true;
        else return false;
    }
    int addNum(int num) {
        int sum = 0;
        while(num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
private:
    set<pair<int, int> > memo_;
};