class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        str = s;
        backtrace(0, 0);
        return res;
    }
private:
    bool isValid(string s){
        if(s[0] == '0' && s.size()>1) return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    void backtrace(int count, int idx) {
        if(count > 4) return;
        if(count == 4 && idx == str.size()) {
            state.pop_back();
            res.push_back(state);
            return;
        } 
        for(int i = idx+1; i <= idx+3 && i <= str.size(); i++) {
            string tmp = state; // 准备回退
            string seg = str.substr(idx, i-idx);
            if(!isValid(seg)) continue;
            state.append(seg+".");
            backtrace(count+1, i);
            state = tmp;
        }
    }
private:
    vector<string> res;
    string state;
    string str;
};