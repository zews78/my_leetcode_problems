class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int min_ans = -1;
        int count_min = 0;

        // if(grid == [[0]])
        bool isEmpty = true;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 || grid[i][j]==2){
                    isEmpty = false;
                }
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

        if(isEmpty) return 0;

        while(!q.empty()){
            int q_len = q.size();

            for(int i=0; i<q_len; i++){
                auto front = q.front();
                q.pop();
                //ULDR
                vector<vector<int>> dir({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});
                for(auto x: dir){
                    int dx = front.first + x[0];
                    int dy = front.second + x[1];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1){
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                    }
                }
            }
            count_min++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return count_min-1;
        
    }
};