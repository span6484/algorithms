class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int value = map[s[i]];
            if(i < n-1 && value < map[s[i+1]]) {
                res -= value;
            } else {
                res += value;
            }
        }
        return res;
    }
private:
    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};