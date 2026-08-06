class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //kahn's algo using BFS
        int V = graph.size();
        vector<int> outdegree(V, 0);//dobara reverse ka indegree nikalne se bach gye

        vector<vector<int>> rev(V);

        for(int i=0; i<V; i++){
            outdegree[i]+=graph[i].size();
            for(auto x: graph[i]){
                rev[x].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0; i<V; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        vector<int> safe_state;

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            safe_state.push_back(front);

            for(auto x: rev[front]){
                outdegree[x]--;
                if(outdegree[x]==0){
                    q.push(x);
                }
            }
        }

        sort(safe_state.begin(), safe_state.end());
        return safe_state;
    }
};