class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> memo(128, 0);
        int counter = t.size();
        int left = 0, right = 0;
        int resIdx = 0;
        int len = INT_MAX;
        for(auto c : t) {
            memo[c]++;
        }

        while(right < s.size()) {
            if(memo[s[right]] > 0) {
                counter--;
            }
            memo[s[right]]--;
            right++;
            while(counter == 0) {
                if(right-left < len) {
                    resIdx = left;
                    len = right - left;
                }
                memo[s[left]]++;
                if(memo[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(resIdx, len);
    }
};