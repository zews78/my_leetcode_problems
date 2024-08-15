class Solution {
public:
    // int solve(int i, int j, int n, vector<vector<int>>& grid){

        //below steps will give wrong answer in many cases cause the approach might not be always optimised.
    //     if(i==n-1 && j==n-1){
    //         return grid[i][j];
    //     }
    //     if(i>=n || j>=n || grid[i][j]==-1){
    //         return INT_MIN;
    //     }
    //     int cherry = grid[i][j];
    //     grid[i][j]=0;
        
    //     int right = solve(i, j+1, n, grid);
    //     int down = solve(i+1, j, n, grid);
    //     // grid[i][j] =cherry;
    //     return cherry+max(right, down);
    // }

    // int solve_back(int i, int j, int n, vector<vector<int>>& grid){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0 || grid[i][j]==-1){
    //         return INT_MIN;
    //     }
        
    //     return grid[i][j]+max(solve(i-1, j, n, grid), solve(i,j-1, n, grid));
    // }
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;
    //     int collection_forward = solve(0, 0, n, grid);
    //     if (collection_forward <= 0) return 0;

    //     int collection_backward=solve_back(n-1, n-1, n, grid);

    //     cout<<collection_forward<<" "<<collection_backward<<endl;
    //     return collection_forward+collection_backward-grid[0][0];
        // return 0;



        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // // int dp[n][n];
        // if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;

        // (grid[0][0]==1)?dp[0][0]=1: dp[0][0]=0;
        // for(int i=1; i<n; i++){
        //     if(grid[i][0]==1){
        //         dp[i][0] = dp[i-1][0]+1;
        //     }
        //     else if(grid[i][0]==0){
        //         dp[i][0] = dp[i-1][0];
        //     }
        //     else{
        //         break;
        //     }
        // }
        // for(int j=1; j<n; j++){
        //     if(grid[0][j]==1){
        //         dp[0][j] = dp[j-1][0]+1;
        //     }
        //     else if(grid[0][j]==0){
        //         dp[0][j] = dp[j-1][0];
        //     }
        //     else{
        //         break;
        //     }
        // }
        // for(int i=1; i<n; i++){
        //     for(int j=1; j<n; j++){
        //         if(grid[i][j]==1){
        //             dp[i][j] = 1+max(dp[i-1][j], dp[i][j-1]);
        //             grid[i][j]=0;
        //         }
        //         else if(grid[i][j]==0){
        //             dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        //         }
        //         else{
        //             dp[i][j]=0;
        //         }
        //     }
        // }

        // //reverse
        // int dp_r[n][n];
        // (grid[n-1][n-1]==1)?dp_r[n-1][n-1]=1: dp_r[n-1][n-1]=0;
        // for(int i=n-2; i>=0; i--){
        //     if(grid[i][n-1]==1){
        //         dp_r[i][n-1] = dp_r[i+1][n-1]+1;
        //     }
        //     else if(grid[i][0]==0){
        //         dp_r[i][n-1] = dp_r[i+1][n-1];
        //     }
        //     else{
        //         break;
        //     }
        // }
        // for(int j=n-2; j>=0; j--){
        //     if(grid[n-1][j]==1){
        //         dp_r[n-1][j] = dp_r[j-1][n-1]+1;
        //     }
        //     else if(grid[0][j]==0){
        //         dp_r[n-1][j] = dp_r[j+1][n-1];
        //     }
        //     else{
        //         break;
        //     }
        // }
        // for(int i=n-2; i>=0; i--){
        //     for(int j=n-2; j>=0; j--){
        //         if(grid[i][j]==1){
        //             dp_r[i][j] = 1+max(dp_r[i+1][j], dp_r[i][j+1]);
        //             grid[i][j]=0;
        //         }
        //         else if(grid[i][j]==0){
        //             dp_r[i][j]= max(dp_r[i+1][j], dp_r[i][j+1]);
        //         }
        //         else{
        //             dp[i][j]=0;
        //         }
        //     }
        // }
        // cout<<dp[n-1][n-1]<<" "<<dp_r[0][0]<<endl;
        // // return dp[n-1][n-1]+dp_r[0][0];
        // return 0;
    
    int solve(int i1, int i2, int j2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        // i1+j1 = i2+j2
        int j1 = i2+j2-i1;
        //base case
        //1.break
        if(i1>=n || i2>=n || j1>=n || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return INT_MIN;
        }
        //2. destination arrived
        if(i1==n-1 && j1==n-1){
            return grid[i1][j1];
        }

        //memoise
        if(dp[i1][i2][j2]!=-1){
            return dp[i1][i2][j2];
        }

        int cherry_count = (i1==i2 && j1==j2)? grid[i1][j1]: grid[i1][j1]+grid[i2][j2];

        //iterate right down in 4 possible ways:
        int down_right = solve(i1+1, i2, j2+1, n, grid, dp);
        int down_down = solve(i1+1, i2+1, j2, n, grid, dp);
        int right_down = solve(i1, i2+1, j2, n, grid, dp);
        int right_right = solve(i1, i2, j2+1, n, grid, dp);
        return dp[i1][i2][j2] = cherry_count + max({down_right, down_down, right_down, right_right});

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        // int ans = 
        return (solve(0, 0, 0, n, grid, dp)<0
        )? 0: solve(0, 0, 0, n, grid, dp);
    }
};