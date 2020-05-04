class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int> &nums, int start, int end) {
        if(start == end) return;
        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    void merge(vector<int>& nums, int l, int m, int h) {
        // l is first index of first subarray, m is last index of first subarray and h is last index of second subarray
        int i = l, j = m + 1;
        vector<int> s;
        
        while(i <= m && j <= h) {
            if(nums[i] <= nums[j]) {
                s.push_back(nums[i++]);
                continue;
            }
            s.push_back(nums[j++]);
        }
        while(i <= m) {
            s.push_back(nums[i++]);
        }
        while(j <= h) {
            s.push_back(nums[j++]);
        }
        for(int k = l; k <= h; k++) {
            nums[k] = s[k - l];
        }
    }
};