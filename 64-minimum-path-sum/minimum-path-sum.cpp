class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        // dp[i][j]=grid[0][0];
        dp[0][1]=0;
        dp[1][0]=1;
        for (int i = 1; i <=m; i++) {
            for (int j = 1; j <=n; j++) {

                    int up = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    dp[i][j] = grid[i-1][j-1] + min(up, left);
                
            }
        }

        return dp[m][n];
    }
};