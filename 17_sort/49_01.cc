class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > map;
        for(auto& str : strs) {
            string key(str);
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string> > res;
        for(auto it = map.begin(); it != map.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};