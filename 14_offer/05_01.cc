class Solution {
public:
    string replaceSpace(string s) {
        string res;
        int prev = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                res += s.substr(prev, i-prev);
                prev = i + 1;
                res += "%20";
            }
        }
        res += s.substr(prev, s.size()-prev);
        return res;
    }
};