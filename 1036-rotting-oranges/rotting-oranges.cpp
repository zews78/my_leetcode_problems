class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();



        queue<tuple<int, int, int>> q;

        vector<vector<int>> dirs({
            {0,1}, {0, -1},
            {-1, 0}, {1, 0}
        });

        int max_time = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            int q_size = q.size();

            for(int i=0; i<q_size; i++){
                auto [x, y, time] = q.front();
                q.pop();

                for(auto dir: dirs){
                    int dx = x+dir[0];
                    int dy = y+dir[1];

                    if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==1){
                        grid[dx][dy]=2;
                        q.push({dx,dy,time+1});
                        max_time = max(max_time, time+1);
                    }
                }

            }

        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return max_time;


        
    }
};