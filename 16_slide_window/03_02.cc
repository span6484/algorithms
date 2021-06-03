class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int l = 0, r = 0;
        int counter = 0;
        vector<int> map(128, 0);
        int res = 1;
        while(r < s.size()) {
            if(map[s[r]] > 0) {
                counter++;
            }
            map[s[r]]++;
            r++;
            while(counter > 0) {
                if(map[s[l]] > 1) counter--;
                map[s[l]]--;
                l++;
            }
            int len = r - l;
            res = max(res, len);
        }
        return res;
    }
};