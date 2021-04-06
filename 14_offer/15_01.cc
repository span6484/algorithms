class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bits(n);
        return bits.count();
    }
};