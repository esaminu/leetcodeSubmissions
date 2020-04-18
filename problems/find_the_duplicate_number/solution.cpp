class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1;
        int j = nums.size() - 1;
        
        while(i < j) {
            int mid = i + (j - i)/2;
            int lessEqCount = accumulate(nums.begin(), nums.end(), 0, [mid](int left, int right) {
                return right <= mid ? left + 1 : left;
            });
            if(lessEqCount > mid) j = mid; else i = mid + 1;
        }
        return i;
    }
};