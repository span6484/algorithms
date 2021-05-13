class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            helper(s, i, i, res);  // 奇数
            helper(s, i, i+1, res); // 偶数
        }
        return res;
    }
private:
    void helper(const string& s, int l, int r, int& res) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }

    }
};