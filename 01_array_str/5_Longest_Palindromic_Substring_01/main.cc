class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int start = 0;
        int len = 0;
        for(int i = 0; i < s.size(); i++) {
            int cur = max(getLen(s, i, i), getLen(s, i, i+1));
            if(cur > len) {
                len = cur;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, len);
    }
private:
    int getLen(const string& s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};