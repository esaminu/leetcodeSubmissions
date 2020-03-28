class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pivot = 1;
        
        int smallest = 0;

          for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) {
              swap(nums[i], nums[smallest++]);
            }
          }

          int largest = nums.size() - 1;

          for(int i = (nums.size() - 1); i >=0 ; i--) {
            if(nums[i] > pivot) {
              swap(nums[i], nums[largest--]);
            }
          }
    }
};