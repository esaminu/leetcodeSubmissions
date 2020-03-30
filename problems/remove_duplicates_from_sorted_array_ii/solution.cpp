class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        int i = 0;
        int n = 2;
        
        for(int j = 1; j<nums.size(); j++) {
            if(i < 1 || nums[j] > nums[i - (n - 1)]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};