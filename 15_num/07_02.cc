class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int max = (INT_MAX - abs(x)%10)/10;
        int min = (INT_MIN + abs(x)%10)/10;
        while(x) {
            if( (x > 0 && res > max) || (x < 0 && res < min) ) return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};

