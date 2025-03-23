class Solution {
public:
    bool dfs(int start, vector<int> &visited, vector<vector<int>>& graph){

        for(auto x: graph[start]){
            if(visited[x]==-1){
                visited[x]=!visited[start];
                if(!dfs(x, visited, graph)){
                    return false;
                }
            }else if(visited[x]==visited[start]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(!dfs(i, visited, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};