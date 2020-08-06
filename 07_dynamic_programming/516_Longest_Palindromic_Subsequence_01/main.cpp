class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int slen = s.size();
        string new_s;
        for(int i = s.size()-1; i >= 0; i--){
            new_s.push_back(s[i]);
        }
        vector<vector<int> > memo(2, vector<int>(slen + 1, 0));
        for(int i = 1; i < slen + 1; i++) {
            for(int j = 1; j < slen + 1; j++) {
                if(s[i - 1] == new_s[j - 1]) {
                    memo[i % 2][j] = memo[(i - 1) % 2][j - 1] + 1;
                }else {
                    memo[i % 2][j] = max(memo[(i - 1) % 2][j], memo[i % 2][j - 1]);
                }
            }
        }
        return memo[slen % 2][slen];
    }
};