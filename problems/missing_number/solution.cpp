class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int expectedTotal =  ((nums.size()*(nums.size() + 1))/2);
        
        if(nums.size() == 1) return nums[0] % 2 ? nums[0] - 1 : nums[0] + 1;
        
        for(int n: nums) total+=n;
        
        return expectedTotal - total;
    }
};