class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) {
            return {};
        }
        if(matrix.size() == 1) {
            return matrix[0];
        }
        vector<int> spiral{};
        int i = 0;
        int size = matrix.size() * matrix[0].size();
        // 00 01 02 12 22 21 20 10
        while(spiral.size() != size) {
            // cout << spiral.size() << size << endl;
            int row = i, col = i;
            // cout << i << "KS"<< row << col<< endl;
            while((col < (matrix[0].size() - i)) && spiral.size() != size) {
                // cout << "L" << "KL" << matrix[row][col] << endl;
                spiral.push_back(matrix[row][col++]);
            }
            col--;
            row++;
            while((row < (matrix.size() - i)) && spiral.size() != size) {
                // cout << row<< "KL2" << col << endl;
                spiral.push_back(matrix[row++][col]);
            }
            row--;
            col--;
            while((col > i) && spiral.size() != size) {
                // cout << row << "KL3" << col << endl;
                spiral.push_back(matrix[row][col--]);
            }
            while((row >= (i+1)) && spiral.size() != size) {
                // cout << "L" << "KL4" << matrix[row][col] << endl;
                spiral.push_back(matrix[row--][col]);
            }
            i++;
        }
        return spiral;
    }
};