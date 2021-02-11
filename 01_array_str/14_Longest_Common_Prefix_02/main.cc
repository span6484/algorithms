class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string str = strs[0];
        for(int i = 0; i < str.size(); i++) {
            char ch = str[i];
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j].size() == i || strs[j][i] != ch) 
                    return str.substr(0, i);
            }
        }
        return str;
    }
};