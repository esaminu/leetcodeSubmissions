class Solution {
public:
    int hammingWeight(uint32_t n) {
        int w = 0;
        
        while(n) {
            w+=1;
            n = n & (n-1);
        }
        return w;
    }
};