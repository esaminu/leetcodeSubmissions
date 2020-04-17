class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int numRequiredInLarger = k - 1;
        int requiredIdx = nums.size() - numRequiredInLarger - 1;
        return findKthLargest(nums, requiredIdx, 0, nums.size() - 1);
    }
    int findKthLargest(vector<int>& nums, int requiredIdx, int i, int j) {
        int idx = partition(i, j, nums);
        if(idx > requiredIdx) return findKthLargest(nums, requiredIdx, i, idx - 1);
        if(idx < requiredIdx) return findKthLargest(nums, requiredIdx, idx + 1, j);
        return nums[idx];
    }
    int partition(int startIndex, int endIndex, vector<int>& vector) {
        int i = startIndex + 1, j = endIndex, pivot = random(startIndex,endIndex);
        
        swap(vector[pivot], vector[startIndex]);
        
        while(i<=j) {
            if(vector[i] > vector[startIndex] && vector[j] <= vector[startIndex]) {
                swap(vector[i], vector[j]);
            }
            if(vector[j] > vector[startIndex]) {
                j--;
            }   
            if(vector[i] <= vector[startIndex]) {
                i++;
            }
        }
        swap(vector[startIndex], vector[j]);
        return j;
    }
    int random(int min, int max) //range : [min, max)
    {
      srand( time(NULL) );
       return min + rand() % (( max + 1 ) - min);
    }
};