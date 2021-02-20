class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size, 0);
        stack<int> st;
        for(int i = 0; i < size; i++) {
            while(!st.empty() && T[i] > T[st.top()]) {
                int idx = st.top(); st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};