class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(auto c: s) {
            map[c]++;
        }
        for(auto c: s) {
            if(map[c] == 1) return c;
        }
        return ' ';
    }
};