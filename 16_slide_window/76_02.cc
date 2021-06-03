class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int counter = 0;
        for(auto c : t) {
            map[c]++;
            counter++;
        }
        int l = 0, r = 0;
        int res = INT_MAX;
        int head = 0;
        while(r < s.size()) {
            if(map[s[r]] > 0) counter--;
            map[s[r]]--;
            r++;
            while(counter == 0) {
                map[s[l]]++;
                if(map[s[l]] > 0) {
                    counter++;
                    int len = r - l;
                    if(len < res) {
                        res = len;
                        head = l;
                    }
                }   
                l++;
            }  

        }
        return res == INT_MAX ? "" : s.substr(head, res);
    }
}; 