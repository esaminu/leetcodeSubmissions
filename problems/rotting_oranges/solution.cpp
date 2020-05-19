struct Node {
    vector<int> coords;
    int time;
};
class Solution {
    vector<vector<int>> dirs{{-1,0}, {0,1}, {1,0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> qu;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    vector<int> v{i, j};
                    qu.push(Node{v, 0});
                }
            }
        }
        int count = 0;
        while(qu.size()) {
            vector<int> curr = qu.front().coords;
            int currTime = qu.front().time;
            qu.pop();
            for(vector<int> dir: dirs) {
                vector<int> next = goToDir(curr, dir);
                if(validateCoord(next, grid)) {
                    grid[next[0]][next[1]] = 2;
                    qu.push(Node{next, currTime + 1});
                }
            }
            if(!qu.size()) count = currTime;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
    bool validateCoord(vector<int> &coord, vector<vector<int>> & grid) {
        int i = coord[0], j = coord[1];
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return false;
        return true;
    }
    vector<int> goToDir(vector<int> &coord, vector<int>& dir) {
        return {coord[0] + dir[0], coord[1] + dir[1]};
    }
};