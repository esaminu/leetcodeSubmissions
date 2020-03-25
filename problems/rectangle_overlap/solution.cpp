class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rangesIntersect( {rec1[0], rec1[2]}, { rec2[0], rec2[2] } ) && rangesIntersect({ rec1[1], rec1[3] }, {rec2[1], rec2[3] } );
    }
    
    bool rangesIntersect(const vector<int> &range1, const vector<int> &range2) {
        bool range1IsBigger = abs(range1[1] - range1[0]) > abs(range2[1] - range2[0]);
        vector<int> biggerRange = range1IsBigger ? range1 : range2;
        vector<int> smallerRange = range1IsBigger ? range2 : range1;
        
        int maxVal = max(biggerRange[0], biggerRange[1]);
        int minVal = min(biggerRange[0], biggerRange[1]);
        
        bool returnVal = ((smallerRange[0] > minVal) &&  (smallerRange[0] < maxVal)) || ((smallerRange[1] > minVal) &&  (smallerRange[1] < maxVal));
        
        return returnVal;
        
    }
};