class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;  
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;
    }
private:
    void dfs(const string& digits, const vector<string>& dict, int cur, string out, vector<string>& res) {
        if(cur == digits.size()) {
            res.push_back(out); 
            return;
        }
        string map = dict[digits[cur] - '0'];
        for(int i = 0; i < map.size(); i++) {
            dfs(digits, dict, cur+1, out+map[i],res );
        }
    }
};