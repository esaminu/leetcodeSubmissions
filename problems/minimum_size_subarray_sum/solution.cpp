class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int currentMinLength = INT_MAX;
        int total = 0;
        int i = 0;
        
        for(int j = 0; j<nums.size(); j++) {
            total += nums[j];
            while(total >= s) {
                currentMinLength = min((j-i) + 1, currentMinLength);
                total -= nums[i];
                i++;
            }
        }
        
        return currentMinLength == INT_MAX ? 0 : currentMinLength;
    }
};