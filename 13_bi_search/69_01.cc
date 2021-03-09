class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long l = 1, r = (long)x + 1;
        while(l < r) {
            long m = l + (r-l) /2;
            if(m > x/m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l-1;   // 因为求出的最小的是 > 的，所以这-1
    }
};