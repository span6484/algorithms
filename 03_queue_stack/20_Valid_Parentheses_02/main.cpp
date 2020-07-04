class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> st;
        for(auto c: s) {
            if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            else if(c == '(') st.push(')');
            else if(st.empty() || st.top() != c) return false;
            else st.pop();
        }
        return st.empty();
    }
};