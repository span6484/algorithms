class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> memo;
            int j = i;
            while(j < n && !memo[s[j]]) {
                memo[s[j++]] = 1;
            }
            res = max(res, j - i);
        }
        return res;
    }
};