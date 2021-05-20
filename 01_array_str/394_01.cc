class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int mul = 0;
        // string 存前缀， int存该乘的因子
        stack<pair<string, int> > st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {  // 如果遇到的是数字
                mul *= 10;
                mul += (s[i] - '0'); 
            } else if(s[i] == '[') {  // 入栈
                st.push({res, mul});
                mul = 0;
                res = "";
            } else if(s[i] == ']') { //
                string suffix = st.top().first;
                int cnt = st.top().second;
                st.pop();
                for(int i = 0; i < cnt; i++) {
                    suffix += res;
                }
                res = suffix;
            } else {  // 遇到字符
                res += s[i];
            }
        }
        return res;
    }
};