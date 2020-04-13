class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](vector<int> left, vector<int> right) {
            float leftDist = sqrt(pow(left[0],2) + pow(left[1],2));
            float rightDist = sqrt(pow(right[0], 2) + pow(right[1], 2));
            return leftDist < rightDist;
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> qu(compare);
        
        for(vector<int> point: points) {
            if(qu.size() < K) {
                qu.push(point);
            } else if(compare(point, qu.top())) {
                qu.pop();
                qu.push(point);
            }
        }
        
        vector<vector<int>> ans;
        while(qu.size()) {
            ans.push_back(qu.top());
            qu.pop();
        }
        return ans;
    }
};