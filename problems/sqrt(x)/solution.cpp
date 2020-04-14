class Solution {
public:
    int mySqrt(int x) {
        long int i = 0;
        long int j = x;
        
        while(i <= j) {
            long int mid = (i + j)/2;
            if(mid * mid == x) {
                return mid;
            }
            if(mid*mid > x) {
                j=mid-1;
            } else {
                i = mid + 1;
            }
        }
        return min(i,j);
    }
};