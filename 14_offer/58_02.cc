class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s += s;
        return s.substr(n, s.size()/2);
    }
};