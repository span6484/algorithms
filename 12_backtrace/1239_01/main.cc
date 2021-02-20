class Solution {
public:
    int maxLength(vector<string>& arr) {
        backtrace(0, "", arr);
        return maxLen;
    }

private: 
    bool hasDuplicate(const string& str) {
        unordered_set<char> s(str.begin(), str.end());
        if (s.size() != str.length()) 
            return true;
        return false;
    }
    void backtrace(int idx, const string& state, vector<string>& arr) {
        maxLen = max(maxLen, static_cast<int>(state.size()));
        if(idx == arr.size()) return;
        for(int i = idx; i < arr.size(); i++) {
            string newstate = state+arr[i];
            if(hasDuplicate(newstate)) continue;
            backtrace(i+1, newstate, arr);
        }
    }
private:
    int maxLen;
};