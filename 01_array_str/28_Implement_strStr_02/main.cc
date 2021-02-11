class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        int n = haystack.size();
        int m = needle.size();
        build(needle);
        int state = 0;
        for(int i = 0; i < n; i++) {
            state = dp[state][haystack[i]];
            if(state == m) return i-m+1;
        }
        return -1;
    }
private:
    void build(const std::string& pat) {
        int m = pat.size();
        dp.resize(m);
        for(int i = 0; i < m; i++) {
            dp[i].resize(256);
        }
        dp[0][pat[0]] = 1;
        int x = 0;
        for(int i = 1; i < m; i++) {
            for(int ch = 0; ch < 256; ch++) {
                if(pat[i] == ch) 
                    dp[i][ch] = i + 1;
                else 
                    dp[i][ch] = dp[x][ch];
            }
            x = dp[x][pat[i]];
        }
    }
    vector<vector<int> > dp;
};