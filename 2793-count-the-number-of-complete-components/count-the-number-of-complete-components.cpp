class Solution {
public:
    void dfs(int i, vector<int> &visited, vector<vector<int>> adj, int &edge_cnt, int &vertices_cnt){
        visited[i]=true;
        vertices_cnt++;
        // cout<<i<<" ";

        for(auto x: adj[i]){
            edge_cnt++;
            if(!visited[x]){
                dfs(x, visited, adj, edge_cnt, vertices_cnt);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //convert to adj list
        vector<vector<int>> adj(n);
        int result=0;
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        //dfs iteration call
        vector<int> visited(n, false);
        for(int i=0; i<n; i++){
            int edge_cnt =0;
            int vertices_cnt =0;
            if(!visited[i]){
                // cout<<visited[i]<<endl;
                dfs(i, visited, adj, edge_cnt, vertices_cnt);
                // cout<<edge_cnt<<vertices_cnt<<endl;
                if(edge_cnt == vertices_cnt*(vertices_cnt-1)){
                    result++;
                }
            }
            
        }
        return result;
    }
};