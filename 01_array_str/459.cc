class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() < 2) return false;
        return kmp(s+s, s);
    }

private:
    bool kmp(const string& txt, const string& pat) {
        int n = txt.size();
        int m = pat.size();
        build(pat);
        int state = 0;
        for(int i = 1; i < n-1; i++) {
            state = memo_[state][txt[i]];
            if(state == m) return true;
        }
        return false;
    }

    void build(const string& pat) {
        int m = pat.size();
        memo_.resize(m);
        for(int i = 0; i < m; i++) {
            memo_[i].resize(128, 0);
        }
        int x = 0;
        // base case 
        memo_[0][pat[0]] = 1;
        for(int i = 1; i < m; i++) {
            for(int ch = 0; ch < 128; ch++) {
                if(pat[i] == ch) {
                    memo_[i][ch] = i+1;
                } else {
                    memo_[i][ch] = memo_[x][ch];
                }
            }
            x = memo_[x][pat[i]];
        }
    }
    vector<vector<int> > memo_;
};