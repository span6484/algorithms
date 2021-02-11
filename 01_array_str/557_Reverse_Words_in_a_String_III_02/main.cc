class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                end = i;
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s.substr(0, end);
    }
};