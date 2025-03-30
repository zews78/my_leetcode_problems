class Solution {
public:
    static const int MOD = 1e9 +7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int n_e = roads[i][1];
            int w= roads[i][2];
            adj[roads[i][0]].push_back({n_e, w});
            adj[n_e].push_back({roads[i][0], w});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0]=0;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, 0});

        vector<int> ways(n, 0);
        ways[0]=1;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long p_node = top.second;
            long long p_weight = top.first;

            for(auto x: adj[p_node]){
                if((long long)p_weight+(long long)x[1] < (long long)dist[x[0]]){
                    dist[x[0]] = p_weight+x[1];
                    ways[x[0]]= ways[p_node] % MOD;
                    pq.push({(long long)p_weight+(long long)x[1], x[0]});
                }else if((long long)p_weight+(long long)x[1] == (long long)dist[x[0]]){
                    ways[x[0]]= (ways[x[0]] + ways[p_node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};