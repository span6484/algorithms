class Solution {
public:
    string replaceSpace(string s) {
        string res;
        s += "1";  // add flag 
        istringstream in(s);
        string tmp;
        int cnt = 0;
        while(getline(in, tmp, ' ')) {
            if(tmp.size()) {
                for(int i = 0; i < cnt; i++) {
                    res += "%20";
                }
                res += tmp;
                cnt = 1;
            } else {
                cnt++;
            }            
        }
        return res.substr(0, res.size()-1);
    }
};