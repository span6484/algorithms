class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        auto memo = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(str1[i-1] == str2[j-1]) memo[i][j] = memo[i-1][j-1] + 1;
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        deque<char> dque;
        while(l1 || l2) {
            char ch;
            if(!l1) ch = str2[--l2];
            else if(!l2) ch = str1[--l1];
            else if(str1[l1-1] == str2[l2-1]) ch = str1[--l1] = str2[--l2];
            else if(memo[l1-1][l2] == memo[l1][l2]) ch = str1[--l1];
            else if(memo[l1][l2-1] == memo[l1][l2]) ch = str2[--l2];
            dque.push_front(ch);
        }
        return string(dque.begin(), dque.end());        
    }
};