class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double ans = 1;
        long num = n;
        if(n < 0){
            num = -num;
            x = 1/x;
        }
        while(num){
            if(num % 2 != 0) ans *= x;
            x *= x;
            num /= 2;
        }
        return ans;
    }
};
