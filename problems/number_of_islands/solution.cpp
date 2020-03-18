struct coord {
    int i;
    int j;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        
        if(!grid.size() || !grid[0].size()) {
            return 0;
        }
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    bfs(i,j,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    char getBelow(coord c, vector<vector<char>>& grid){return c.i < grid.size() - 1 ? grid[c.i+1][c.j] : '0';}
    char getAbove(coord c, vector<vector<char>>& grid){return c.i != 0 ? grid[c.i-1][c.j] : '0';}
    char getRight(coord c, vector<vector<char>>& grid){return c.j < grid[0].size() - 1 ? grid[c.i][c.j+1] : '0';}
    char getLeft(coord c, vector<vector<char>>& grid){return c.j != 0 ? grid[c.i][c.j - 1] : '0';}
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        std::queue<coord> myqueue;
        coord c;
        c.i = i;
        c.j = j;
        grid[c.i][c.j] = '0';
        myqueue.push(c);
        
        while(!myqueue.empty()) {
            coord d = myqueue.front();
            myqueue.pop();
            
            if(getLeft(d,grid) == '1') {
                c.i = d.i;
                c.j = d.j - 1;
                grid[c.i][c.j] = '0';
                myqueue.push(c);
            }
            if(getAbove(d,grid) == '1') {
                c.i = d.i - 1;
                c.j = d.j;
                grid[c.i][c.j] = '0';
                myqueue.push(c);
            }
            if(getBelow(d,grid) == '1') {
                c.i = d.i + 1;
                c.j = d.j;
                grid[c.i][c.j] = '0';
                myqueue.push(c);
            }
            if(getRight(d,grid) == '1') {
                c.i = d.i;
                c.j = d.j + 1;
                grid[c.i][c.j] = '0';
                myqueue.push(c);
            }
            
            
        }
        
        
    }
};