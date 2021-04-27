class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> memo;
        for(auto& i : s) {
            memo[i]++;
        }
        for(auto& i : t) {
            if(memo[i] <= 0) return false;
            memo[i]--;
        }
        return true;
    }
};