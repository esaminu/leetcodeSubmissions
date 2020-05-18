class Solution {
private:
    vector<vector<int>> dirs{{0,1}, {0, -1}, {1,0}, {-1, 0}};
    bool validateCoords(vector<int>& coords, vector<vector<char>> & grid) {
        int i = coords[0], j = coords[1];
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return false;
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>> & grid, int i, int j) {
        queue<vector<int>> qu;
        qu.push({i,j});
        grid[i][j] = '0';
        while(qu.size()) {
            vector<int> curr = qu.front();
            qu.pop();
            for(vector<int> dir : dirs) {
                vector<int> next= goInDir(curr, dir);
                if(validateCoords(next, grid)) {
                    grid[next[0]][next[1]] = '0';
                    qu.push(next);
                } 
            }
        }
    }
    void dfs(vector<vector<char>> & grid, int i, int j) {
        vector<int> curr{i,j};
        if(!validateCoords(curr, grid)) return;
        grid[i][j] = '0';
        for(vector<int> dir: dirs) {
            vector<int> next = goInDir(curr, dir);
            dfs(grid, next[0], next[1]);
        }
    }
    vector<int> goInDir(vector<int>& coord, vector<int> &dir) {
        return {coord[0] + dir[0], coord[1] + dir[1]};
    }
};