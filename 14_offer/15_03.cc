/*
如果是2的幂的话
恒有 n & (n - 1) == 0，这是因为：
n 二进制最高位为 1，其余所有位为 0；
n−1 二进制最高位为 0，其余所有位为 1；

0001  0000	(0001) & (0000) == 0

0010  0001	(0010) & (0001) == 0

0100  0011	(0100) & (0011) == 0

1000  0111	(1000) & (0111) == 0

而这道题

0001 0110  n-1 0001 0101  n & n-1 : 0001 0100  // 最低位1变成了0
0001 0100  n-1 0001 0011  n & n-1 : 0001 0000  // 最低位1变成了0

...

*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
};