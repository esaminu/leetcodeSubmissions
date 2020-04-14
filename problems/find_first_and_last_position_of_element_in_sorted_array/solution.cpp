class Solution {
public:
    template <class T>
    int binSearchIndex(vector<T>& nums, T target, bool last) {
        int i = 0, j = nums.size() - 1, m = -1;
        
        while(i <= j) {
            int mid = (i + j)/2;
            if(nums[mid] == target) {
                 m = mid;
                if(last) {
                   i = mid + 1; 
                } else {
                    j = mid - 1;
                }
            }
            if(nums[mid] < target) {
                i = mid + 1;
            }
            if(nums[mid] > target) {
                j = mid - 1;
            }
        }
        return m;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binSearchIndex(nums, target, false), binSearchIndex(nums, target, true)};
    }
};