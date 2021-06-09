class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(auto& word : wordDict) {
                int sz = word.size();
                if(i - sz >= 0 && s.substr(i-sz, sz) == word) {
                    dp[i] = dp[i] || dp[i-sz];
                }
            }
        }      
        return dp[s.size()];
    }
};