class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n==0) return -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int distance =1;
        vector<vector<int>> dirs({{1,0}, {1,1}, {0,1}, {-1,0}, {-1, 1}, {0, -1,}, {-1, -1},{1, -1}});
        // 0 -> 1, -1;
        // 1 -> 0, 1, -1;
        // -1 -> 0, 1, -1;

        while(!q.empty()){
            int q_size = q.size();

            for(int i=0; i<q_size; i++){
                auto [x, y] = q.front();
                q.pop();

                if(x==n-1 && y==n-1){
                    return distance;
                }

                for(auto dir: dirs){
                    int dx = x + dir[0];
                    int dy = y + dir[1];


                    if(dx>=0 && dy>=0 && dx<n && dy<n && grid[dx][dy]==0){
                        q.push({dx, dy});
                        grid[dx][dy]=1;

                    }
                }
            }
            distance++;
        }
        return -1;


    }
};