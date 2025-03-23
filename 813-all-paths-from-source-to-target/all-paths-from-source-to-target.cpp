class Solution {
public:
    void getAllPaths(int start, int n, vector<vector<int>>& graph, vector<int> currPath, vector<vector<int>> &allPaths){
        currPath.push_back(start);
        if(start==n-1){
            allPaths.push_back(currPath);
        }

        for(auto x: graph[start]){
            getAllPaths(x, n, graph, currPath, allPaths);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> allPaths;
        vector<int> currPath;
        getAllPaths(0, n, graph, currPath, allPaths);
        return allPaths;
    }
};