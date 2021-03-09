
class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = (long)n + 1;
        while(l < r) {
            long m = l + (r-l)/2;
            if(isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};