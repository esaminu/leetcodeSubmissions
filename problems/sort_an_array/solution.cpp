class Solution {
    int randomCall = 0;
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int> &arr, int low, int high) {
        if(low < high) {
            int newIndex = partitionAroundPivot(low, high, getRandomNumber(low, high), arr);
            quickSort(arr, low, newIndex);
            quickSort(arr, newIndex + 1, high);
        }
    }
    int partitionAroundPivot(int start, int end, int pivotIndex, vector<int> &arr) {
        // returns final pivot index. start and end inclusive
        int i = start, j = end, pivot = arr[pivotIndex], currPivotIndex = pivotIndex;
        
        while(i <= j) {
            if(arr[i]>= pivot && arr[j] < pivot) {
                if(i == currPivotIndex) currPivotIndex = j; else if(j == currPivotIndex) currPivotIndex = i;
                swap(arr[i++], arr[j--]);
                continue;
            }
            if(arr[i] < pivot) {
                i++;
            }
            if(arr[j] >= pivot) {
                j--;
            }
        }
        swap(arr[currPivotIndex], arr[j + 1]);
        return j + 1;
    }
    int getRandomNumber(int min, int max) {
        // inclusive
        srand(randomCall++);
        return min + (rand() % (max - min + 1));
    }
};