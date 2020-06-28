class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> st;
        st.push('#');
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }
            if(st.top() == '{' && s[i] == '}') st.pop();
            else if(st.top() == '[' && s[i] == ']') st.pop();
            else if(st.top() == '(' && s[i] == ')') st.pop();
            else return false;
        }
        st.pop();
        if(!st.empty()) return false;
        return true;
    }
};