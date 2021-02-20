class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const auto& c : s) {
            if(st.empty()) st.push(c);
            else {
                auto top = st.top();
                if( (top == '(' && c == ')') 
                || (top == '[' && c == ']') 
                || (top == '{' && c == '}') ) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};