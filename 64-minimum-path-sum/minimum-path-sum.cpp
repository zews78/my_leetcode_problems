class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int dp[n][m];
        int sumi=0;
        for(int i=0; i<n; i++){
            sumi += grid[i][0];
            dp[i][0] = sumi;
        }
        int sumj = 0;
        for(int j=0; j<m; j++){
            sumj += grid[0][j];
            dp[0][j] = sumj;
        }
        // memset(dp, 0, sizeof(dp));
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};