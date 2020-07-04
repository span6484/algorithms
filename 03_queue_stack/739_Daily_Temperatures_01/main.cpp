class Solution {
    
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len);
        stack<int> s;
        for(int i = 0; i < len; i++) {
            while(!s.empty() && T[i] > T[s.top()]) {
                int idx = s.top();
                res[idx] = i - idx;
                s.pop();
            } 
            s.push(i);
        }
        return res;

    }
};