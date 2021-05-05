class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            if( (x > 0 &&(INT_MAX - x%10)/10 < res) || (x < 0 && (INT_MIN - x%10)/10 > res) ) return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};
