class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int next_even = 0, next_odd = A.size() - 1;
        
        while(next_even < next_odd) {
            if(A[next_even] % 2 == 0) {
                ++next_even;
            } else {
                swap(A[next_even], A[next_odd--]);
            }
        }
        return A;
//         vector<int>::iterator evenItr = A.begin();
//         vector<int>::iterator oddItr = A.begin();
        
//         while(evenItr != A.end() && oddItr != A.end()) {
//             bool evenIsEven = *evenItr % 2 == 0;
//             bool oddIsOdd = *oddItr % 2 != 0;
//             if(evenIsEven && oddIsOdd) {
//                 if(oddItr < evenItr) {
//                     iter_swap(oddItr++,evenItr++);
//                     continue;
//                 }
//                 evenItr++;
//                 continue;
//             }
//             if(!evenIsEven) {
//                 evenItr++;
//             }
//             if(!oddIsOdd) {
//                 oddItr++;
//             }
//         }
//         return A;
    }
};