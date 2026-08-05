class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();

        int org_color = grid[row][col];

        dfs(row, col, org_color, grid);


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==-1001){
                    grid[i][j]=color;
                }else if(grid[i][j]==-org_color){
                    grid[i][j]=org_color;
                }
            }
        }

        return grid;

        
        
    }

    void dfs(int i, int j, int org_color, vector<vector<int>>& grid){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||  abs(grid[i][j]) != org_color || grid[i][j]<0){
            return;
        }

        grid[i][j]=-org_color; //visited+coloring
        bool isBorder=false;

        // if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
        //     isBorder=true;
        // }


        for(auto dir: dirs){
            int dx=dir[0]+i;
            int dy=dir[1]+j;


            if(dx<0 || dy<0 || dx>=grid.size() || dy>=grid[0].size()){
                isBorder=true;
                continue;
            }

            if(abs(grid[dx][dy])!=org_color && grid[dx][dy]!=-1001){
                isBorder=true;
            }

            if(grid[dx][dy] == org_color)
            {
                dfs(dx, dy, org_color, grid);
            }
        }
        if(isBorder){
            grid[i][j]=-1001;
        }
    }


};