class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int land_cells=0;

        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                dfs(i, 0, grid);
            }
            if(grid[i][m-1]==1){
                dfs(i, m-1, grid);
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j]==1){
                dfs(0, j, grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1, j, grid);
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    land_cells++;
                }
            }
        }

        return land_cells;
    }
    vector<vector<int>> dirs = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};

    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j]= 0;

        for(auto dir: dirs){
            int dx = dir[0]+i;
            int dy = dir[1]+j;

            if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && grid[dx][dy]==1){
                dfs(dx, dy, grid);
            }
        }
    }
};