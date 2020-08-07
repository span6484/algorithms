class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse_helper(s, 0);
    }

    void reverse_helper(vector<char>& s, int i) {
        if(i == s.size() / 2) return;
        swap(s[i], s[s.size() -i - 1]);
        return reverse_helper(s, i + 1);
    }
};