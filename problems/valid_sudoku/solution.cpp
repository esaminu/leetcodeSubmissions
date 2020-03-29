class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return validRows(board) && validCols(board) && valid33s(board);
    }
    
    bool validRows(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); i++) {
            unordered_map<int, int> freq;
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                      if(freq[board[i][j]]) {
                        return false;
                      } else {
                        freq[board[i][j]] = 1; 
                      }  
                }
            }
        }
        return true;
    }
    
    bool valid33s(vector<vector<char>>& board) {
        int startI = 0;
        int startJ = 0;
        
        int endJ = (startJ + 9);
        while(startJ != endJ) {
            if(startI == 9) {
                startI = 0;
            } 
            int endI = (startI + 9);
            while(startI != endI) {
                int i = startI;
                int j = startJ;
                int endj = j + 3;
                unordered_map<int, int> freq;
                while(j != endj) {
                    if(i == (startI + 3)) {
                        i = startI;
                    } 
                    int endi = i + 3;
                    while(i != endi) {
                        if(board[j][i] != '.') {
                          if(freq[board[j][i]]) {
                            // freq[board[j][i]] += 1;
                            return false;
                          } else {
                            freq[board[j][i]] = 1; 
                          }  
                        }
                        
                        i++;
                    }
                    j++;
                }
                startI+=3;
            }
            startJ+=3;
        }
        return true;
    }
    bool validCols(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); i++) {
            unordered_map<int, int> freq;
            for(int j = 0; j < board[0].size(); j++) {
                if(board[j][i] != '.') {
                      if(freq[board[j][i]]) {
                        return false;
                      } else {
                        freq[board[j][i]] = 1; 
                      }  
                }
            }
        }
        return true;
    }
};