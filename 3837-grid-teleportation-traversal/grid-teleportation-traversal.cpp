class Solution {
public:
    int minMoves(vector<string>& matrix) {
        vector<vector<pair<int, int>>> portal(26);

        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> usedPortal(26, false);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch = matrix[i][j];
                if(ch>='A' && ch<='Z'){
                    portal[ch-'A'].push_back({i, j});
                }
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0]= 0;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1){
                return cost;
            }

            char ch = matrix[x][y];
            // cout<<ch<<" ";





            if(ch>='A' && ch<='Z' && !usedPortal[ch-'A']){
                usedPortal[ch-'A'] = true;
                for(auto [i, j]: portal[ch-'A']){
                    if(dist[i][j]>cost){
                        dist[i][j] = cost;
                        pq.push({cost, i, j});
                    }
                }
            }

            vector<pair<int, int>> dir({{0,1}, {1,0}, {-1, 0}, {0,-1}});
            for(auto [dx, dy]: dir){
                int xi = x+dx;
                int yj = y+dy;
                if(xi >= 0 && xi < n && yj >= 0 && yj < m && matrix[xi][yj] != '#'){
                    if(dist[xi][yj]> cost+1){
                        dist[xi][yj] = cost+1;
                        pq.push({cost+1, xi, yj});
                    }
                }
            }
        }
        return -1;

        
        
    }

};