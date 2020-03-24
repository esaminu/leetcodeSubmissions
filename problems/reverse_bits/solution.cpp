class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       int mask16 = 0xFFFF;
        
        return (reverse16(n & mask16) << 16) | (reverse16((n & (mask16 << 16)) >> 16));
    }
    
    int reverse16(int n) {
        int reversed = 0;
        while(n) {
            int isoBit = n & ~(n-1);
            reversed |= (int) pow(2, 15 - (log2(isoBit)));
            n &= (n -1);
        }
        return reversed;
    }
};