class Solution {
public:
    double myPow(double x, int n) {
        return n > 0? helper(x, n, 1) : 1 / helper(x, -1 * long(n) , 1);
    }

    double helper(double x, int n, double res) {
        if(n == 0) return res;
        res = n % 2 ? res * x : res;
        return helper(x * x, n / 2, res);
    }
};