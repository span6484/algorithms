class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        unordered_map<char, int> m;
        int res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            if(m.find(s[j]) != m.end()) i = max(i, m[s[j]] + 1);
            m[s[j]] = j;
            res = max(res, j-i+1);
        }
        return res;
    }
};