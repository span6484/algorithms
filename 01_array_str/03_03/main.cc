class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, 0);
        int start = 0, end = 0;
        int counter = 0, len = 0;
        while(end < s.size()) {
            if(map[s[end]] > 0) {
                counter++;
            }
            map[s[end]]++;
            end++;
            while(counter > 0) {
                if(map[s[start]] > 1) {
                    counter--;
                }
                map[s[start]]--;
                start++;
            }
            len = max(len, end-start);
        }
        return len;
    }
};