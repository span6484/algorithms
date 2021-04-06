class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int sz = str.size();
        vector<int> dp(sz);
        dp[0] = 1;
        for(int i = 1; i < sz; i++) {
            dp[i] = dp[i-1];
            if(str[i-1] != '0' && stoi(str.substr(i-1, 2)) < 26) {
                dp[i] += i >= 2? dp[i-2] : 1;
            }
        }
        return dp[sz-1];
    }
};