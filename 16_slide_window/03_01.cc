class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int l = 0, r = 0;
        unordered_map<int, int> map;
        int res = 1;
        while(r < s.size()) {
            map[s[r]]++;
            r++;
            for(int i = l; i < r; i++) {
                if(map[s[i]] > 1) {
                    for(int j = l; j <= i; j++) {
                        map[s[j]]--;
                    }
                    l = i+1;
                    break;
                }
            }
            int len = r - l;
            res = max(len ,res);
        }
        return res;
    }
};