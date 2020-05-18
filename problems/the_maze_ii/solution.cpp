class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;
        vector<vector<int>> dirs{{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<vector<int>> qu;
        qu.push(start);
        
        while(qu.size()) {
            vector<int> curr = qu.front();
            int currDist = distance[curr[0]][curr[1]];
            qu.pop();
            
            for(vector<int> dir : dirs) {
                vector<int> dirrCurr = curr;
                int count = 0;
                
                for(vector<int> next = addDirToCoord(dirrCurr, dir); (next[0] >=0) && (next[0] < maze.size()) && (next[1]>=0) && (next[1] < maze[0].size()) && (maze[next[0]][next[1]] == 0); next = addDirToCoord(dirrCurr, dir)) {
                    count++;
                    dirrCurr = next;
                }
                
                if((currDist + count) < distance[dirrCurr[0]][dirrCurr[1]]) {
                    qu.push(dirrCurr);
                    distance[dirrCurr[0]][dirrCurr[1]] = currDist + count;
                }
                
            }
        }
        return distance[destination[0]][destination[1]] < INT_MAX ? distance[destination[0]][destination[1]] : -1;
    }
    vector<int> addDirToCoord(vector<int> &coord, vector<int> &dir) {
        return {coord[0] + dir[0], coord[1] + dir[1]};
    }
};