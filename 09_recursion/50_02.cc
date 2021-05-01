class Solution {
public:
    double myPow(double x, int n) {
        return n > 0? helper(x, n) : 1.0/helper(x, n);
    }
private:
    double helper(double x, int n) {
        if(n == 0) return 1;
        return helper(x*x, n/2) * (n % 2 ? x : 1);
    }
};