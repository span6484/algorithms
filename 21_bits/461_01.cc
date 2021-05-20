class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int cnt = 0;
        while(t) {
            cnt += t & 1;  // 只看最后一位
            t >>= 1;
        }
        return cnt;
    } 
};