class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        int target = graph.size() - 1;
        
        dfsSearch(0, target, graph, {}, paths);
        return paths;
    }
    void dfsSearch(int node, int target, vector<vector<int>> &graph, vector<int> currPath, vector<vector<int>> &paths) {
        currPath.push_back(node);
        if(node == target) {
            paths.push_back(currPath);
        }
        for(int n : graph[node]) {
            dfsSearch(n, target, graph, currPath, paths);
        }
    }
};