class Solution {
public:
    bool dfs(int start, vector<vector<int>> &graph, vector<bool>& visited, vector<bool>& pathVisited){
        visited[start] = true;
        pathVisited[start] = true;

        for(auto x: graph[start]){
            if(pathVisited[x] && visited[x]){
                return true;
            }
            else if(!visited[x]){
                if(dfs(x, graph, visited, pathVisited)){
                    return true;
                }
            }
            
        }
        pathVisited[start] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect cycle in dag

        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            graph[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, graph, visited, pathVisited)){
                    return false;
                }
            }
        }
        return true;
    }
};