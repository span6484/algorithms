class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) return res;
        dfs("", n, n, res);
        return res;
    }
private:
    void dfs(string s, int left, int right, vector<string>& res) {
        if(left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if(left == right) {  // 左右括号相等，下一个一定是左
            dfs(s+"(", left-1, right, res);
        } else if(left < right) {
            if(left > 0) {
                dfs(s+"(", left-1, right, res);
            }
            dfs(s+")", left, right-1, res);
        }
    }
};