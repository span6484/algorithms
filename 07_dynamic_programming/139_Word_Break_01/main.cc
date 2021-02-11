class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(const auto& word: wordDict) {
            memo_.emplace(word, true);
        }
        return helper(s);
    }

private:
    bool helper(const string& s) {
        if(memo_.count(s)) return memo_[s];
        for(int i = 1; i < s.size(); i++) {
            auto it = memo_.find(s.substr(i));
            if(it != memo_.end() && it->second && helper(s.substr(0, i))) {
                return memo_[s] = true;
            }
        }
        return memo_[s] = false;
    }
private:
    unordered_map<string, bool> memo_;
};