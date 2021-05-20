## 461. Hamming Distance 01

先求亦或，然后来看有多少个bit为1

t&1就是看最后一位是否是1

t>>=1 不断移位

O(1)

O(1)

## 461. Hamming Distance 02

利用__builtin_popcount

计算32位无符号整数有多少个为1的bit

