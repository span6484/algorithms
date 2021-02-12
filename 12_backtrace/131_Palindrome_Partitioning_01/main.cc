class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrace(s);
        return res;
    }   

private:
    bool isPalindrome(const string& str) {
        int len = str.size();
        for(int i = 0; i < len/2; i++) {
            if(str[i] != str[len-i-1]) return false;
        }
        return true;
    }
    void backtrace(const string& s) {
        if(!s.size()) {
            res.push_back(state);
        }
        for(int i = 0; i < s.size(); i++) {
            string prefix = s.substr(0, i+1);
            if(!isPalindrome(prefix)) continue;
            state.push_back(prefix);
            backtrace(s.substr(i+1));
            state.pop_back();
        }
    }
private:
    vector<vector<string> > res;
    vector<string> state;
};