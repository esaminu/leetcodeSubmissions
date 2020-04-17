class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size() - 1]) return nums[0]; // array is not rotated 
        int i = 0, j = nums.size() - 1;
        
        return findInflectionPoint(nums, i, j);
    }
    int findInflectionPoint(const vector<int>& nums,int i,int j) {
        if(i == j) return nums[i];
        
        int mid = i + (j - i)/2;
        
        if(nums[mid] > nums[j]) return findInflectionPoint(nums, mid + 1, j);
        
        return findInflectionPoint(nums, i, mid); // cant rule out mid as min (so no mid - 1)
    }
};