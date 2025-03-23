class Solution {
public:
    bool bfs(int start, vector<int> &visited, vector<vector<int>>& graph){
        queue<int> q;

        q.push(start);
        visited[start]=0;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto it: graph[top]){
                if(visited[it]==-1){
                    q.push(it);
                    visited[it]=!visited[top];
                }
                else if(visited[it]==visited[top]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i]==-1){
                if(!bfs(i, visited, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};