class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        for(int i = 0; i < deadends.size(); i++) {
            ma[deadends[i]] = 1;
        }
        string init = "0000";
        if(ma[init] == 1) return -1;
        queue<string> q;
        q.push(init);
        int ret = -1;
        while(!q.empty()) {
            int qLen = q.size();
            ret++;
            for(int i = 0; i < qLen; i++) {
                string tmp = q.front();
                q.pop();
                if(tmp == target) {
                    return ret;
                }
                if(ma[tmp] != 1) {
                    ma[tmp] = 1;
                    for(int i = 0; i < 4; i++) {
                        string a = tmp; 
                        string b = tmp;                     
                        a[i] = a[i] == '9' ? '0' : a[i] + 1;
                        b[i] = b[i] == '0' ? '9' : b[i] - 1;
                        if(ma[a] != 1) q.push(a);    
                        if(ma[b] != 1) q.push(b);               
                    }
                }
            }
        }
        return -1;

    }

private:
    unordered_map<string, int> ma;
};
