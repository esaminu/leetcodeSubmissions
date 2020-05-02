class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size()) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<int> currInterval = intervals[0];
        vector<vector<int>> merged;
        
        for(int i = 1; i <intervals.size(); i++) {
            if(intervals[i][0] <= currInterval[1] && intervals[i][1] >= currInterval[0]) {
                currInterval[0] = min(intervals[i][0],currInterval[0]);
                currInterval[1] = max(intervals[i][1], currInterval[1]);
            } else {
                merged.push_back(currInterval);
                currInterval = intervals[i];
            }
        }
        merged.push_back(currInterval);
        return merged;
    }
};