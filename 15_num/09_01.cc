class Solution {
public:
    bool isPalindrome(int x) {
        string a = std::to_string(x);
        int i = 0, j = a.size()-1;
        while(i < j) {
            if(a[i] == a[j]) {
                i++; j--;
            } else {
                return false;
            }
        }
        return true;
    }
};