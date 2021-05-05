class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string pre = s.substr(0, n);
        int sz = s.size();
        s += pre;
        return s.substr(n, sz);
    }
};