class Solution {
    public int numIslands(char[][] grid) {
        if(grid == null) {
            return 0;
        }
        int islands = 0;
        int width = grid.length > 0 ? grid[0].length : 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < width; j++ ) {
                char str = grid[i][j];
                if(str == '1' ) {
                   islands += 1;
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
    public void bfs(char[][] grid, int i, int j) {
        Queue<Eyejay> q = new LinkedList<>();
        q.add(new Eyejay(i,j));
        
        while(!q.isEmpty()) {
            Eyejay currIJ = q.poll();
            int currI = currIJ.i;
            int currJ = currIJ.j;
            char topVal = (currI > 0) ? grid[currI-1][currJ] : '0';
            char bottomVal = (currI < grid.length - 1) ? grid[currI+1][currJ] : '0';
            char rightVal = (currJ < grid[0].length - 1) ? grid[currI][currJ + 1] : '0';
            char leftVal = (currJ > 0)  ? grid[currI][currJ - 1] : '0';
            
            grid[currI][currJ] = '0';  
            if(topVal == '1') {
                grid[currI - 1][currJ] = 0;
                q.add(new Eyejay(currI-1, currJ));
            }
            if(bottomVal == '1') {
                grid[currI + 1][currJ] = 0;
                q.add(new Eyejay(currI+1, currJ));
            }
            if(rightVal == '1') {
                grid[currI][currJ + 1] = 0;
                q.add(new Eyejay(currI, currJ + 1));
            }
            if(leftVal == '1') {
                grid[currI][currJ - 1] = 0;
                q.add(new Eyejay(currI, currJ - 1));
            }
              
        }
    }
}

class Eyejay {
    int i;
    int j;
    public Eyejay(int i, int j) {
        this.i = i;
        this.j = j;
    }
    public void show() {
        System.out.println(i + " | " + j);
    }
}