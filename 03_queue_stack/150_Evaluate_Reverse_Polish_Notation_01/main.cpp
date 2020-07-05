class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> st;
        int a, b;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b + a);
            } else if(tokens[i] == "-") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b - a);
            } else if(tokens[i] == "*") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b * a);
            } else if(tokens[i] == "/") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
            }else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
