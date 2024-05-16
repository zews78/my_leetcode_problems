class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int n, int m){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return 0;
        }
        int max_val= 0;
        int originalVal = grid[i][j];
        grid[i][j]=0;
        max_val = max(max_val, solve(i+1, j, grid, n, m)+originalVal);
        max_val = max(max_val, solve(i, j+1, grid, n, m)+originalVal);
        max_val = max(max_val, solve(i-1, j, grid, n, m)+originalVal);
        max_val = max(max_val, solve(i, j-1, grid, n, m)+originalVal);
        grid[i][j]= originalVal;
        return max_val;
    }



    // void solve(int i, int j, vector<vector<int>> &grid, int n, int m, int ans, int &maxx){
    //     //base case
    //     if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
    //         maxx = max(ans, maxx);
    //         return;
    //     }
    //     int originalVal = grid[i][j];
    //     grid[i][j]=0;
    //     solve(i+1, j, grid, n, m, ans+originalVal, maxx);
    //     solve(i, j+1, grid, n, m, ans+originalVal, maxx);
    //     solve(i-1, j, grid, n, m, ans+originalVal, maxx);
    //     solve(i, j-1, grid, n, m, ans+originalVal, maxx);
    //     grid[i][j]= originalVal;
    //     // return max_val;

    // }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_count =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int gold_count = solve(i, j, grid, n, m);
                max_count = max(max_count, gold_count);
            }
        }
        // int maxx = grid[i][j];
        // int maxx= 9;
        // return solve(2,1, grid, n, m);
        // return maxx;
        return max_count;
    }
};