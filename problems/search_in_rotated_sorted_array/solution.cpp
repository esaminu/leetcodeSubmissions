class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        
        return findTargetIndex(i, j, nums, target);
        
    }
    int findTargetIndex(int i, int j, vector<int> nums, int target) {
        if(i > j) return -1;
        int mid = i + (j - i)/2;
        if(nums[mid] > target) {
            if(nums[mid] > nums[j]) {
                if(target >= nums[i]) {
                    return findTargetIndex(i, mid - 1, nums, target);
                }
                return findTargetIndex(mid + 1, j, nums, target);
            }
            return findTargetIndex(i, mid - 1, nums, target);
        }
        if(nums[mid] < target) {
            if(nums[mid] > nums[j]) {
                 return findTargetIndex(mid + 1, j, nums, target);
            }
            if(target <= nums[j]) {
                return findTargetIndex(mid + 1, j, nums, target);
            }
            return findTargetIndex(i, mid - 1, nums, target);
        }
        return mid; // nums[mid] == target
    }
};