class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> state(V, 0);
        vector<int> safe_state;

        for(int i=0; i<V; i++){
            if(dfs(i, V, graph, state)){
                safe_state.push_back(i);
            }
        }

        return safe_state;

    }


    bool dfs(int i, int V, vector<vector<int>>& graph, vector<int> &state){
        if(state[i]==1){
            return false;
        }

        if(state[i]==2){
            return true;
        }

        state[i]=1;

        for(auto x: graph[i]){
            if(!dfs(x, V, graph, state)){
                return false;
            }
        }

        state[i]=2;
        return true;
    }
};